/*
** ia.c for  in /home/bauwen_j/rendu/my_git/test
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sat Feb  8 14:51:14 2014 bauwen_j
** Last update Sat Feb  8 14:51:14 2014 bauwen_j
*/

#include <stdlib.h>
#include "my.h"

void	my_quit(char *str)
{
  my_putstr(str);
  exit(0);
}

char	**new_tab(char **tab, char *line, char *allum)
{
  char	**ntab;
  int	l;
  int	a;

  l = my_unsigned_int(line) - 1;
  a = my_unsigned_int(allum);
  if (a == my_strlen(tab[l]))
    {
      ntab = sous_line(tab, l);
      return (ntab);
    }
  else
    {
      tab[l] = sous_allum(a, my_strlen(tab[l]));
      return (tab);
    }
}

int	check_one(char **tab)
{
  int	nb_plus;
  int	i;

  i = 0;
  nb_plus = 0;
  while (tab[i] != 0)
    {
      if (my_strlen(tab[i]) > 1)
	nb_plus++;
      i++;
    }
  return (nb_plus);
}

char	**ia(char **tab)
{
  int	i;
  int	sizet;

  i = 0;
  while (tab[i] != 0 && my_strlen(tab[i]) == 1)
    i++;
  sizet = my_size_tab(tab);
  if (sizet % 2 != 0)
    {
      if (check_one(tab) > 0 && sizet == 3)
	tab[i] = sous_allum(my_strlen(tab[i]) - 1, my_strlen(tab[i]));
      else if (check_one(tab) == 0)
	tab = sous_line(tab, sizet - 1);
      else
	tab[i] = sous_allum(my_strlen(tab[i]) - 1, my_strlen(tab[i]));
    }
  else
    {
      if (sizet == 2 && check_one(tab) == 2)
	tab[1] = sous_allum(my_strlen(tab[1]) - 1, my_strlen(tab[1]));
      else
	tab = sous_line(tab, sizet - 1);
    }
  return (tab);
}
