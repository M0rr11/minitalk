#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//LIBFT

int	    ft_atoi(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int     ft_strlen(const char *str);

//
void    printexit(char *error);
int     check_pid(char *pid);

#endif