/*
** display.c for  in /home/broggi_t/projets/sudoku/srcs
** 
** Made by 
** Login   <broggi_t@epitech.net>
** 
** Started on  Fri Feb 28 21:13:06 2014 
** Last update Sun Mar  2 21:47:00 2014 
*/

#include <stdlib.h>
#include "my_str.h"
#include "sudo.h"

static void	display_bar()
{
  my_putchar(SIDE);
  my_putnchar(TOP, LINE_SIZE - 2);
  my_putchar(SIDE);
  my_putchar('\n');
}

static void	display_color(char nb)
{
  my_putstr("\033[0;32m");
  my_putchar(nb + 48);
  my_putstr("\033[0m");
}

static void	display_std(char nb)
{
  if (nb >= '1' && nb <= '9')
    my_putchar(nb);
  else
    my_putchar(nb + 48);
}

int		display(char **map, char color)
{
  int		i;
  int		j;

  i = -1;
  display_bar();
  while (++i < 9)
    {
      my_putchar(SIDE);
      j = -1;
      while (++j < 9)
	{
	  my_putchar(SEPARATOR);
	  if (map[i][j] == 0 || map[i][j] == MORE)
	    my_putchar(SEPARATOR);
	  else if (map[i][j] >= 1 && map[i][j] <= 9 && color == 1)
	    display_color(map[i][j]);
	  else
	    display_std(map[i][j]);
	}
      my_putchar(SIDE);
      my_putchar('\n');
    }
  display_bar();
  return (SUCCESS);
}
