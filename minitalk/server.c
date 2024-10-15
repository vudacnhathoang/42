#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handle_signal(int signal) {
    if (signal == SIGINT) {
        printf("CTRl + C - end of server\n");
        exit(0);
    } else if (signal == SIGTERM) {
        printf("Killing signals - end of server\n");
    } else if(signal == SIGUSR1) {
        printf("Received signal: %d\n", signal);
    }
        else if (signal == SIGUSR2) {
        printf("Received signal: %d\n", signal);
        }
}
int main(void)
{
    int pid = getpid();
    printf("PID - %d\n", pid);

    signal(SIGINT,handle_signal);
    signal(SIGTERM,handle_signal); 
    signal(SIGUSR1,handle_signal);
    signal(SIGUSR2,handle_signal);
    while(1)
    {
        printf("Waiting for signal\n");
        pause();
    }
    return 0;
}
