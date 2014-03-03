/*
** sqare_per_sqare.c for  in /home/bauwen_j/test/sudoku/srcs
** 
** Made by bauwens
** Login   <bauwen_j@epitech.net>
** 
** Started on  Sat Mar  1 16:10:35 2014 bauwens
** Last update Sun Mar  2 13:25:14 2014 bauwens
*/

#include "sudo.h"

int	check_in_square(int x, int y, int val, char **map)
{
  int	pos;
  int	i;
  int	j;

  i = x + 3;
  j = y + 3;
  pos = 0;
  while (x < i)
    {
      y = j - 4;
      while (++y < j)
	if ((map[x][y] == MORE || map[x][y] == 0) &&
	    (check_all(x, y, val, map) == 1))
	  {
	    if (pos == 0)
	      pos = x * 10 + y;
	    else
	      return (FAILURE);
	  }
      ++x;
    }
  return (pos);
}

int	in_square(char **map, int x, int y)
{
  int	pos;
  int	val;
  int	status;

  val = '1';
  while (val <= '9')
    {
      if (check_square(x, y, val, map) == 1)
	{
	  if ((pos = check_in_square(x, y, val, map)) != FAILURE)
	    {
	      map[pos / 10][pos % 10] = val;
	      status = SUCCESS;
	    }
	  else
	    {
	      if (status != SUCCESS)
		status = FAILURE;
	    }
	}
      ++val;
    }
  return (status);
}

int	check_per_square(char **map)
{
  int	i;
  int	j;
  int	status;

  i = 0;
  while (i < 9)
    {
      j = 0;
      while (j < 9)
	{
	  status = in_square(map, i, j);
	  j += 3;
	}
      i += 3;
    }
  return (status);
}
