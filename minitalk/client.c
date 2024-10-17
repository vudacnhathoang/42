#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>



void char_to_binary(char c, int pid)
{
    int i;
    i = 7;
    int j;

    while (i >= 0) 
    {  
        j = ((c >> i) & 1);
        if (j == 1) {
            kill(pid, SIGUSR2);
        } else {
            kill(pid, SIGUSR1);
        }
        i--;
        usleep(42);
    }

}


int main (int ac, char *av[])
{
    int i;

    i = 0;
    if (ac != 3) {
        printf("Usage: %s <pid>\n", av[1]);
        return (1);
    }
    int pid = atoi(av[1]);
    kill(pid, SIGUSR1);
    while (av[2][i]) 
    {
        char_to_binary(av[2][i],pid);
        i++;
    }
    char_to_binary('\0',pid);
}
