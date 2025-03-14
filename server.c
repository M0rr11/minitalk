#include "minitalk.h"

void handle_signal(int sig, siginfo_t *info, void *context)
{
    static unsigned char current_char;
    static int bit_count;
    static int f = 1;

    (void)context;
    if(f == 1)
    {
        f = 0;
        if (kill(info->si_pid, SIGUSR1) == -1)
            write(1, "Kill not working\n", 17);
    }
    else
    {
        if (sig == SIGUSR1)
            current_char |= (1 << (7 - bit_count));
        bit_count++;
        if (bit_count == 8)
        {
            write(1, &current_char, 1);
            if (current_char == '\0')
            {
                write(1, "\n", 1);
                f = 1;
             }
            current_char = 0;
            bit_count = 0;
        }
    }
    if (kill(info->si_pid, SIGUSR1) == -1)
    printexit("Error: Failed to send acknowledgment\n");
}

int main()
{
    struct sigaction        sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &handle_signal;
    ft_putstr_fd("Server ID : ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n", 1);
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
            printexit("Error : sigaction function");
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
            printexit("Error : sigaction function");
    ft_putstr_fd("Server is running...\n", 1);
    while (1)
        pause();
    return 0;
}
