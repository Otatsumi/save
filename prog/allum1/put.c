/*
** put.c for  in /home/bauwen_j/rendu/lib
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sat Jan 25 14:46:04 2014 bauwen_j
** Last update Sat Jan 25 14:46:04 2014 bauwen_j
*/

#include <unistd.h>

void    my_putchar(char c)
{
  write(1, &c, 1);
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

void    my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_size_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    i++;
  return (i);
}
