/*
** battle.c for  in /home/bauwen_j/rendu/my_git/test
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Fri Feb  7 17:54:17 2014 bauwen_j
** Last update Fri Feb  7 17:54:17 2014 bauwen_j
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

char	*sous_allum(int a, int sizel)
{
  char	*str;
  int	i;
  int	stop;

  stop = sizel - a;
  if ((str = malloc(stop + 1 * sizeof(char))) == NULL)
    my_quit("error : malloc failed\n");
  i = 0;
  while (i != stop)
    {
      str[i] = '|';
      i++;
    }
  str[stop + 1] = 0;
  return (str);
}

char	**sous_line(char **tab, int l)
{
  char	**ntab;
  int	i;
  int	j;

  if ((ntab = malloc(my_size_tab(tab) * sizeof(char*))) == NULL)
    my_quit("error : malloc failed\n");
  i = 0;
  j = 0;
  while (tab[i] != 0 && i < my_size_tab(tab))
    {
      if (i != l)
	{
	  ntab[j] = tab[i];
	  j++;
	}
      i++;
    }
  ntab[j] = 0;
  return (ntab);
}

char	*nb_line(char **tab)
{
  char	*line;

  line = NULL;
  while (line == NULL || check_line(tab, line) == -1)
    {
      my_putstr("enter the number of line\n");
      if ((line = get_next_line(0)) == NULL)
	my_quit("error : get_next_line failed\n");
    }
  return (line);
}

char	*nb_allum(char **tab, char *line)
{
  char	*allum;

  allum = NULL;
  while (allum == NULL || check_allum(tab, line, allum) == -1)
    {
      my_putstr("enter the number of matchstick\n");
      if ((allum = get_next_line(0)) == NULL)
	my_quit("error : get_next_line failed\n");
    }
  return (allum);
}

void	battle(char **tab, int nb_a)
{
  char	*line;
  char	*allum;

  my_putstr("the battle beggin for 1 player\n");
  while (nb_a != 0)
    {
      my_put_tab(tab);
      line = nb_line(tab);
      allum = nb_allum(tab, line);
      tab = new_tab(tab, line, allum);
      my_put_tab(tab);
      my_putchar('\n');
      nb_a = al_tab(tab);
      if (nb_a == 0)
	{
	  my_putstr("you loose\n");
	  exit(0);
	}
      tab = ia(tab);
      nb_a = al_tab(tab);
    }
  my_putstr("you win\n");
}
