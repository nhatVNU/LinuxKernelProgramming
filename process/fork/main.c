#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Note: The parent process and the child process run in separate memory spaces (they run in parallel with each other). 
The child process copies all the data and the model of its parent, except for the location on the other memory */

int main(int argc, char *argv[]){
    __pid_t child_pid;
    int counter = 2;
    printf("Initialized value of counter: %d\n", counter);
    child_pid = fork();
    if(child_pid >= 0){     /* Success */
        if(child_pid == 0){ /* child process*/
            printf("\nI am the child process: %d\n", ++counter);
            printf("\nMy PID: %d and my parent PID: %d\n", getpid(), getppid());
        }else{              /* parent process */
            printf("\nI am parent process: %d\n", ++counter);
            printf("\nMy PID: %d\n", getpid());
        }
    }else{                  /* Failed if return -1*/
        printf("\nFailed to fork()\n");
    }
    return 0;
}