#include "minitalk.h"

char *msg;

void    signal_handler(int sig, siginfo_t *info, void *ucontext)
{
    static int i = 7;
    static int bit = 0;
    unsigned char c;

    (void)sig;
    (void)ucontext;
    c = msg[bit];
    if ((c >> i & 1) == 1)
    {
      if (kill(info->si_pid, SIGUSR1) == -1)
        printexit("Invalid Process Id\n");
    }
    else if((c >> i & 1) == 0)
    {
      if (kill(info->si_pid, SIGUSR2) == -1)
        printexit("Invalid Process Id\n");
    }
    i--;
    if(i < 0)
    {
        bit++;
        i = 7;
        if (bit == ft_strlen(msg) + 1)
          printexit("message receved\n");
    }
}

int main(int ac, char **av)
{
    struct sigaction        sa;
    int                     pid;
  
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &signal_handler;
    if (ac != 3 || !av[1][0] || !av[2][0])
            printexit("Usage : ./client <server_pid> <message>\n");
    pid = ft_atoi(av[1]);
    if (check_pid(av[1]) || pid <= 0)
            printexit("Error : Bad ID\n");
    msg = av[2];
    if (kill(pid, SIGUSR1))
            printexit("Error: kill function!\n");
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
            printexit("Error : sigaction function");
    while (1)
            pause();
  
}
