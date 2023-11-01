#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


/* If the child process is killed/terminated before its parent => The process child is not completed delete from system, 
it still has some info such as PID and stop status (We can not kill child process because it die) => The child becomes the Zombie process  */

/* To prevent creating many zombie process in system (leak memory):

1. Always call wait() in parent process (But if the child process calls while(1), the parent must be wait forever ...)
2. Using SIGCHLD

*/

int main(int argc, char *argv[])
{
    pid_t childPID;
    int status, retvalue;
    childPID = fork();
    if(childPID >= 0){
        if(childPID == 0){  /* child process */
            printf("Child process termination %d\n", getpid());
        }else{              /* parent process */
            // while(1);
            retvalue = wait(&status);   /* Wait will delete zombie child process */

        }
    }else{
        printf("fork() failed\n");
    }
    return 0;
}