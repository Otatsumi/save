/*
** algo.c for  in /home/broggi_t/projets/sudoku/srcs
** 
** Made by 
** Login   <broggi_t@epitech.net>
** 
** Started on  Sat Mar  1 00:38:41 2014 
** Last update Sun Mar  2 19:31:09 2014 
*/

#include "sudo.h"

static int	is_solved(char **map)
{
  int		i;
  int		j;

  i = -1;
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
	{
	  if (map[i][j] == 0 || map[i][j] == MORE)
	    return (0);
	}
    }
  return (1);
}

int		algo(char **map)
{
  int		i;
  int		j;
  int		status;

  while (!is_solved(map))
    {
      status = 0;
      i = -1;
      while (++i < 9)
	{
	  j = -1;
	  while (++j < 9)
	    if (map[i][j] == 0 || map[i][j] == MORE)
	      {
		if (get_value(i, j, map) != map[i][j])
		  {
		    ++status;
		    map[i][j] = get_value(i, j, map);
		  }
	      }
	}
      if (status == 0 && check_per_square(map) == FAILURE)
	return (FAILURE);
    }
  return (SUCCESS);
}
