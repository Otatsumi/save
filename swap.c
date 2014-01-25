/*
** swap.c for  in /home/bauwen_j/rendu/lib
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sat Jan 25 14:47:24 2014 bauwen_j
** Last update Sat Jan 25 14:47:24 2014 bauwen_j
*/

#include "my.h"

void    my_swap(int *a, int *b)
{
  int   c;

  c = *a;
  *a = *b;
  *b = c;
}

int     my_getnbr(char *str)
{
  int   nb;
  int   i;

  i = 0;
  nb = 0;
  while (str[i] != 0)
    {
      nb = (nb * 10) + (str[i] - 48);
      i++;
    }
  return (nb);
}

int     my_getnbr_base(char *str, char *base)
{
  int	nb;
  int	size;
  int	i;
  int	j;

  size = my_strlen(base);
  i = 0;
  while (str[i] != 0)
    {
      j = 0;
      while (base[j] != str[i])
	j++;
      nb = (nb * size) + j;
      i++;
    }
  return (nb);
}
