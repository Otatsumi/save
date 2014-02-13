/*
** main.c for  in /home/bauwen_j/rendu/my_git/test
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Fri Feb  7 16:58:07 2014 bauwen_j
** Last update Fri Feb  7 16:58:07 2014 bauwen_j
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

int	al_tab(char **tab)
{
  int	j;
  int	i;
  int	nb_al;

  i = 0;
  nb_al = 0;
  while (tab[i] != 0)
    {
      j = 0;
      while (tab[i][j] != 0)
	{
	  j++;
	  nb_al++;
	}
      i++;
    }
  return (nb_al);
}

char	**my_tab(int i)
{
  char	**tab;
  int	endallum;
  int	allum;
  int	line;

  endallum = 1;
  line = 0;
  if ((tab = malloc((i + 1) * sizeof(char*))) == NULL)
    my_quit("error : malloc failed\n");
  while (line < i)
    {
      allum = 0;
      if ((tab[line] = malloc(endallum + 1 * sizeof(char))) == NULL)
    my_quit("error : malloc failed\n");
      while (allum < endallum)
	{
	  tab[line][allum] = '|';
	  allum++;
	}
      tab[line][allum] = 0;
      endallum = endallum + 2;
      line++;
    }
  tab[line] = 0;
  return (tab);
}

void	ready(char **tab, int nb_a)
{
  char	*str;

  my_putstr("enter 1 for 1 player and 2 for 2 player\n");
  if ((str = get_next_line(0)) == NULL)
    {
      my_putstr("sorry, get_next_line failed\nyou play with IA\n");
      battle(tab, nb_a);
    }
  else
    {
      if (my_unsigned_int(str) == 2)
	{
	  my_putstr("the battle beggin for 2 player\n");
	  two_player(tab, nb_a);
	}
      else if (my_unsigned_int(str) == 1)
	battle(tab, nb_a);
      else
	battle(tab, nb_a);
    }
}

int	main(int ac, char **argv)
{
  int	nb_line;
  int	nb_allum;
  char	**tab;

  if (ac == 1)
    nb_line = 4;
  else
    {
      if (my_unsigned_int(argv[1]) < 4
	  || my_unsigned_int(argv[1]) < 0
	  || my_unsigned_int(argv[1]) > 60)
	{
	  my_putstr("sorry 4 line minimum and 60 maximum\n");
	  nb_line = 4;
	}
      else
	nb_line = my_unsigned_int(argv[1]);
    }
  if ((tab = my_tab(nb_line)) == NULL)
    return (0);
  nb_allum = al_tab(tab);
  ready(tab, nb_allum);
  return (0);
}
