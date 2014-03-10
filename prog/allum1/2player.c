/*
** 2player.c for  in /home/bauwen_j/rendu/my_git/alum1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Tue Feb 11 18:10:13 2014 bauwen_j
** Last update Tue Feb 11 18:10:13 2014 bauwen_j
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

void	two_player(char **tab, int nb_a)
{
  char	*line;
  char	*allum;

  while (nb_a != 0)
    {
      my_put_tab(tab);
      my_putstr("player 1\n");
      line = nb_line(tab);
      allum = nb_allum(tab, line);
      tab = new_tab(tab, line, allum);
      my_put_tab(tab);
      my_putchar('\n');
      nb_a = al_tab(tab);
      if (nb_a == 0)
	{
	  my_putstr("player 1 loose, player 2 win\n");
	  exit(0);
	}
      my_putstr("player 2\n");
      line = nb_line(tab);
      allum = nb_allum(tab, line);
      tab = new_tab(tab, line, allum);
      nb_a = al_tab(tab);
    }
  my_putstr("player 2 loose, player 1 win\n");
}
