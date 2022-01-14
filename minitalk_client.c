#include "libft.h"
#include <sys/types.h>
#include <signal.h>

static void send_char(pid_t pid, unsigned char c) {
    char    byte;
    
    byte = 1 << 6;
    while (byte != 0) {
        if (byte & c) {
            if (kill(pid, SIGUSR1) == -1)
            {
                ft_putstr_fd("Invalid PID", 1);
                exit(0);
            }
        } else {
            if (kill(pid, SIGUSR2) == -1) {
            ft_putstr_fd("Invalid PID", 1);
                exit(0);
            }
        }
        byte >>= 1;
        usleep(100);
    }
}

static void send_message(char *pid_str, char *message) {
    int     i;
    pid_t   pid;

    i = 0;
    pid = ft_atoi(pid_str);
    while (message[i])
    {
        send_char(pid, message[i]);
        i++;
    }
    send_char(pid, message[i]);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        ft_putstr_fd("usage ./client <server-pid> <message>\n", 1);
        return (0);
    }
    send_message(argv[1], argv[2]);
    return (0);
}