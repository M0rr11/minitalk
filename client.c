#include "minitalk.h"

void send_bit(int pid, int bit)
{
    if (bit == 0)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);

    usleep(500);  
}
void    send_msg(int pid, char *msg)
{
    int i;
    int bit;
    unsigned char c;

   
    while(*msg)
    {
        c = *msg;
        i = 7;
        while(i >= 0)
        {
            bit = (c >> i) & 1;
            send_bit(pid,bit);
            i--;
        }
        msg++;
    }
}

int main(int ac, char **av)
{
  if(ac != 3)
  {
    const char *error_msg;
    error_msg = "Usage: <server_pid> <message>\n";
    write(2, error_msg, 30);
    return 1;
  }
  int pid;
  char *msg;

  pid = ft_atoi(av[1]);
  msg = av[2];
  send_msg(pid, msg);
  return 0;
}
