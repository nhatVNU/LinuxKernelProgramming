#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]){
    printf("Starting kill this process...\n");
    sleep(2);
    kill(getpid(), SIGKILL);

    while(1){
        printf("You killed failed\n");
        sleep(1);
    }
    return 0;
}