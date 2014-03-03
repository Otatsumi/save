/*
** my_str.c for  in /home/broggi_t/minish
** 
** Made by broggi_t
** Login   <broggi_t@epitech.net>
** 
** Started on  Wed Dec 18 12:46:25 2013 broggi_t
** Last update Fri Feb 28 22:08:59 2014 
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_str.h"

int		my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}

int		my_putnchar(char c, int nb)
{
  int		i;

  i = -1;
  while (++i < nb)
    my_putchar(c);
  return (0);
}

int		my_strlen(char *str)
{
  int		i;

  if (str == NULL)
    return (-1);
  i = -1;
  while (str[++i]);
  return (i);
}

int		my_putstr(char *str)
{
  if (str == NULL)
    return (-1);
  write(1, str, my_strlen(str));
  return (0);
}

int		my_puterr(char *str)
{
  if (str == NULL)
    return (-1);
  write(2, str, my_strlen(str));
  return (0);
}
