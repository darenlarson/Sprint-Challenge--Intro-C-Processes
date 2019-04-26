**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Created - a process has been created, but has not been run yet.
Sleep - a process has been loaded and started running, but is waiting to continue running.
Zombie - a process is done and waiting to be terminated.
Running - a process is currenting being executed by the OS



**2. What is a zombie process?**
A process whoses execution is completed, but it remains in the process table, waiting for an exit() system call.


**3. How does a zombie process get created? How does one get destroyed?**
If, for example, the parent of a child zombie process fails to eventually call exit(), the zombie process may persist and cause issues.
Per google, you can also kill zombies using the command kill -s SIGCHILD


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled languages tend to be faster than non-compiled langauges because there is no intermediate interpretor layer (you're writing in the native code of the machine).
You can write more optimized code for the machine you're running it on.