#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char **argv)
{

  // -------- Parse command line --------
  char *dir_path;

  if (argc > 1) {
    dir_path = argv[1];

    // if no additional commandline args entered, use the current directory
  } else {
    dir_path = ".";
  }


  // -------- Open directory: call opendir() --------
  // Pass the dir_path entered into the command line into DIR directory. This opens the directory stored in char `dir_path` and returns a POINTER to a variable of type DIR.
  DIR *d = opendir(dir_path);

  // opendir() returns NULL if there is an error
  if (d == NULL) {
    printf("%s is an invalid directory\n", dir_path);
    exit(1);
  }


  // -------- Repeatly read and print entries: call readdir() --------
  struct dirent *ent;
  struct stat buf;

  printf("\nType\t Size\t Name\n");
  
  while ((ent = readdir(d)) != NULL) {
    stat(ent->d_name, &buf);

    // --- printf() for MVP ---
    // printf("%lld\t %s\n", buf.st_size, ent->d_name);


    // --- STRETCH ---
    if (buf.st_mode == 16877) {
      char *type = "<DIR>";

      printf("%s\t %lld\t %s\n", type, buf.st_size, ent->d_name);

      DIR *sub_d = opendir(ent->d_name);
        while((ent = readdir(sub_d)) != NULL) {
          stat(ent->d_name, &buf);
          if (buf.st_mode == 16877) {
            type = "<DIR>";
            printf("\t %s\t %lld\t %s\n", type, buf.st_size, ent->d_name);
          } else {
            printf("\t %hu\t %lld\t %s\n", buf.st_mode, buf.st_size, ent->d_name);
          }
        }

    } else {
      printf("%hu\t %lld\t %s\n", buf.st_mode, buf.st_size, ent->d_name);
    }


  }

  printf("\n");

  // Close directory
  closedir(d);


  return 0;
}