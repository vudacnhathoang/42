#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>



int main (int ac, char *av[])
{
    int pid = atoi(av[1]);
    int signal = atoi(av[2]);
    printf("PID - %d\n", pid);
    printf("Signal - %d\n", signal);
    if (signal == 1) {
        kill(pid, SIGUSR1);
    } else if (signal == 2) {
        kill(pid, SIGUSR2);
    }  else if (signal == 15) {
        kill(pid, SIGTERM);
    }
    return 0;
}
