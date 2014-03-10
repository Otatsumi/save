/*
** puttab.c for  in /home/bauwen_j/rendu/my_git/alum1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Mon Feb 10 14:18:27 2014 bauwen_j
** Last update Mon Feb 10 14:18:27 2014 bauwen_j
*/

#include <unistd.h>
#include "my.h"

int	search_big(char **tab)
{
  int	i;
  int	tall;

  i = 1;
  tall = 0;
  while (tab[i] != 0)
    {
      if (my_strlen(tab[tall]) < my_strlen(tab[i]))
	  tall = i;
      i++;
    }
  return (tall);
}

void	my_putline(char	*str, int size)
{
  int	size_str;
  int	nb_space;

  size_str = my_strlen(str) / 2;
  size = size / 2;
  nb_space = 0;
  while (size_str + nb_space < size)
    nb_space++;
  while (nb_space > 0)
    {
      write(1, " ", 1);
      nb_space--;
    }
  my_putstr(str);
  my_putchar('\n');
}

void	my_put_tab(char **tab)
{
  int	i;
  int	big;

  i = 0;
  big = search_big(tab);
  while (tab[i] != 0)
    {
      my_putline(tab[i], my_strlen(tab[big]));
      i++;
    }
}
