/*
** get_next_line.c for get_next_line in /home/bauwen_j/rendu/get_next_line
** 
** Made by bauwens
** Login   <bauwen_j@epitech.net>
** 
** Started on  Mon Nov 18 09:35:33 2013 bauwens
** Last update Tue Nov 26 15:16:45 2013 bauwens
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int		size(char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    i = i + 1;
  return (i);
}

char		*my_newbuf(char *buffer, char *str)
{
  char		*new_str;
  int		i;
  int		j;

  i = size(buffer);
  new_str = malloc((i + SIZE_READ + 1) * sizeof(char));
  if (new_str == NULL)
      return (NULL);
  i = 0;
  while (buffer[i] != 0)
    {
      new_str[i] = buffer[i];
      i = i + 1;
    }
  j = 0;
  while (str[j] != 0)
    {
      new_str[i] = str[j];
      j = j + 1;
      i = i + 1;
    }
  new_str[i] = 0;
  free (buffer);
  return (new_str);
}

int		size_newbuf(int last_n, char *buffer)
{
  int		i;

  i = last_n;
  while (buffer[i] != '\n' && buffer[i] != 0)
    i = i + 1;
  return (i);
}

char		*aff_str(char *buffer, int nb_read)
{
  char		*str;
  static int	last_n = 0;
  int		i;
  int		j;

  i = size_newbuf(last_n, buffer);
  if ((nb_read - (i + 1) + 1) > 0)
    {
      str = malloc(i *sizeof(char));
      if (str == NULL)
	return (NULL);
      i = last_n;
      j = 0;
      while (buffer[i] != '\n' && buffer[i] != 0)
	{
	  str[j] = buffer[i];
	  j = j + 1;
	  i = i + 1;
	}
      last_n = i + 1;
      str[j] = 0;
      return (str);
    }
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static char	* buffer = NULL;
  static int	nb_read = 0;
  int		rest;
  char		*str;

  if (fd < 0)
    return (NULL);
  rest = SIZE_READ;
  if (buffer == NULL)
    {
      buffer = malloc((SIZE_READ + 1) * sizeof(char));
      if (buffer == NULL)
	return (NULL);
    }
  str = malloc((SIZE_READ + 1) * sizeof(char));
  if (str == NULL)
    return (NULL);
  while (rest == SIZE_READ)
    {
      rest = read(fd, str, SIZE_READ);
      nb_read = nb_read + rest;
      str[rest] = 0;
      buffer = my_newbuf(buffer, str);
    }
  return (aff_str(buffer, nb_read));
}
