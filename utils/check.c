#include "../minitalk.h"

void    printexit(char *error)
{
        ft_putstr_fd(error, 1);
        exit(1);
}

int     check_pid(char *pid)
{
        int     i;

        i = 0;
        while (pid[i])
        {
                if (!(pid[i] >= '0' && pid[i] <= '9'))
                        return (1);
                i++;
        }
        return (0);
}
