/*
** grid.c for  in /home/broggi_t/projets/sudoku/srcs
** 
** Made by 
** Login   <broggi_t@epitech.net>
** 
** Started on  Sat Mar  1 03:12:58 2014 
** Last update Sun Mar  2 19:20:41 2014 
*/

#include <stdlib.h>
#include "my_str.h"
#include "get_next_line.h"
#include "sudo.h"

static int	check_top_line()
{
  char		*readed;
  int		i;

  if ((readed = get_next_line(0)) == NULL)
    return (FAILURE);
  if (my_strlen(readed) != LINE_SIZE || readed[0] != SIDE ||
      readed[LINE_SIZE - 1] != SIDE)
    {
      my_puterr(INVALID_LINE);
      return (FAILURE);
    }
  i = 0;
  while (++i < LINE_SIZE - 1)
    {
      if (readed[i] != TOP)
	{
	  my_puterr(INVALID_LINE);
	  return (FAILURE);
	}
    }
  free(readed);
  return (SUCCESS);
}

static int	check_std_line(char **grid, int line)
{
  char		*readed;
  int		i;

  if ((readed = get_next_line(0)) == NULL)
    return (FAILURE);
  if (my_strlen(readed) != LINE_SIZE || readed[0] != SIDE ||
      readed[LINE_SIZE - 1] != SIDE)
    {
      my_puterr(INVALID_LINE);
      return (FAILURE);
    }
  i = 2;
  while (i < LINE_SIZE - 1)
    {
      if (readed[i] >= '1' && readed[i] <= '9')
	grid[line][i / 2 - 1] = readed[i];
      else if (readed[i] == ' ')
	grid[line][i / 2 - 1] = 0;
      else
	return (FAILURE + my_puterr(INVALID_LINE));
      i += 2;
    }
  free(readed);
  return (SUCCESS);
}

char		**get_grid()
{
  char		**grid;
  int		i;

  if ((grid = malloc(10 * sizeof(char *))) == NULL ||
      check_top_line() == FAILURE)
    return (NULL);
  grid[9] = NULL;
  i = -1;
  while (++i < 9)
    {
      if ((grid[i] = malloc(10 * sizeof(char))) == NULL)
	return (NULL);
      if (check_std_line(grid, i) == FAILURE)
	return (NULL);
    }
  if (check_top_line() == FAILURE)
    return (NULL);
  return (grid);
}
