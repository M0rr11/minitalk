#include "minitalk.h"

unsigned char current_char = 0;
int bit_count = 0;

void signal_handler(int signum)
{
  printf("Received SIGINT! ... Exiting\n");
  exit(0);
}

void handle_SIGUSR1(int sig)
{
    current_char <<= 1; 
    bit_count++;

    if (bit_count == MAX_BITS)
    {
        write(1, &current_char, 1);
        current_char = 0; 
        bit_count = 0;
    }
}


void handle_SIGUSR2(int sig)
{
    current_char <<= 1;
    current_char |= 1;
    bit_count++;

    if (bit_count == MAX_BITS)
    {
        write(1, &current_char, 1);
        current_char = 0;
        bit_count = 0;
    }
}

int main()
{
    printf("My process ID (PID) is: %d\n", getpid());
    fflush(stdout);
    signal(SIGINT, signal_handler);
    signal(SIGUSR1, handle_SIGUSR1);
    signal(SIGUSR2, handle_SIGUSR2);

    while(1)
    {
         pause();
    }

}
