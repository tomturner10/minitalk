#include <sys/types.h>
#include <stddef.h>
#include "libft.h"

static  void reciever(int sig) {
    static char byte;
    static int count;
   
    byte <<= 1;
    count++;
    if (sig == SIGUSR1)
    {
        signal(SIGUSR1, reciever);
        byte++;
    } else if (sig == SIGUSR2)
        signal(SIGUSR2, reciever);
    if (count == 7)
    {
        write(1, &byte, 1);
        byte = 0;
        count = 0;
    }
    
}

int main(void) {
    pid_t   pid;
    pid = getpid();
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    signal(SIGUSR1, reciever);
    signal(SIGUSR2, reciever);
    while (1)
        pause();
    return (0);
}