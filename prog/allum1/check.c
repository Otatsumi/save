/*
** check.c<2> for  in /home/bauwen_j/rendu/my_git/test
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Fri Feb  7 18:55:23 2014 bauwen_j
** Last update Fri Feb  7 18:55:23 2014 bauwen_j
*/

#include <stdlib.h>
#include "my.h"

int	check_line(char **tab, char *line)
{
  int	l;
  int	tab_line;

  l = my_unsigned_int(line);
  if (l < 0)
    {
      my_putstr("error : number positiv only\n");
      return (-1);
    }
  tab_line = 0;
  while (tab[tab_line] != 0)
    tab_line++;
  if (l > tab_line)
    {
      my_putstr("error : number is too big\n");
      return (-1);
    }
  return (0);
}

int	check_allum(char **tab, char *line, char *allum)
{
  int	a;
  int	l;
  int	nb_a;

  l = my_unsigned_int(line) - 1;
  a = my_unsigned_int(allum);
  if (a < 0)
    {
      my_putstr("error : number positiv only\n");
      return (-1);
    }
  nb_a = my_strlen(tab[l]);
  if (a > nb_a)
    {
      my_putstr("error : number is too big\n");
      return (-1);
    }
  return (0);
}
