#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* Open the other shell terminal, enter: `ps aux | prep <main>` to find PID of the main process. Let kill it: `kill -9 <PID>` */

int main(int argc, char *argv[])
{
    pid_t childPID; 
    int status, retval;
    childPID = fork();
    if(childPID >= 0){
        if(childPID == 0){  /* Child process */
            printf("This is %d child process!\n", getpid());
            while(1){
                sleep(5);   /* Wait for 5 seconds to exit normally */
                exit(0);
            }
        }else{              /* Parent process */
            printf("This is %d parent process, my child process: %d\n", getpid(), childPID);
            retval = wait(&status);
            if(retval == -1){
                printf("wait() failed\n");
            }
            if(WIFEXITED(status)){
                printf("Child process exited normally with status = %d\n", WEXITSTATUS(status));
            }else if(WIFSIGNALED(status)){
                printf("Child process exited abnormally with signal number = %d\n", WTERMSIG(status));
            }
        }
    }else{
        printf("fork() failed\n");
    }
    return 0;
}

