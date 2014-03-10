/*
** getnext.c for  in /home/bauwen_j/rendu/psu/PSU_2013_minishell1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sun Jan 26 14:14:37 2014 bauwen_j
** Last update Sun Jan 26 14:14:37 2014 bauwen_j
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char            *my_newbuf(char *buffer, char *str)
{
  char          *new_str;
  int           i;
  int           j;

  i = my_strlen(buffer);
  new_str = malloc((i + SIZE_READ + 1) * sizeof(char));
  if (new_str == NULL || buffer == NULL || str == NULL)
    return (NULL);
  i = 0;
  while (buffer[i] != 0 && buffer[i] != '\n')
    {
      new_str[i] = buffer[i];
      i = i + 1;
    }
  j = 0;
  while (str[j] != 0 && str[j] != '\n')
    {
      new_str[i] = str[j];
      j = j + 1;
      i = i + 1;
    }
  new_str[i] = 0;
  free (buffer);
  return (new_str);
}

int             check_n(char *str)
{
  int           i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '\n')
        return (1);
      i++;
    }
  return (0);
}

char            *get_next_line(const int fd)
{
  static char   *buffer = NULL;
  char          *str;
  int           rest;

  if (fd < 0)
    return (NULL);
  rest = SIZE_READ;
  while (rest == SIZE_READ)
    {
      if ((str = malloc((SIZE_READ + 1) * sizeof(char))) == NULL)
        return (NULL);
      if ((buffer = malloc((SIZE_READ + 1) * sizeof(char))) == NULL)
	return (NULL);
      if ((rest = read(fd, str, SIZE_READ)) == -1)
        return (NULL);
      str[rest] = 0;
      if (check_n(str) == 1)
        return (my_newbuf(buffer, str));
      buffer = my_newbuf(buffer, str);
      if (buffer == NULL)
        return (NULL);
      free(str);
    }
  return (NULL);
}
