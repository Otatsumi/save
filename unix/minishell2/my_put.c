/*
** my_put.c for  in /home/bauwen_j/rendu/psu/PSU_2013_minishell1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sun Jan 26 14:16:43 2014 bauwen_j
** Last update Sun Jan 26 14:16:43 2014 bauwen_j
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

void    my_put(char *str)
{
  write(1, str, my_strlen(str));
}

int     sizetab(char *str, char c, int i)
{
  while (str[i] != 0 && str[i] != c)
    i++;
  return (i);
}

char    **my_sort_wordtab(char *str, char c)
{
  int   i;
  int   j;
  int   k;
  char  **my_list;

  j = 0;
  i = 0;
  if ((my_list = malloc((my_strlen(str) + 1) * sizeof(char*))) == NULL)
    return (NULL);
  while (str[i] != 0 && i < my_strlen(str))
    {
      while (str[i] == c)
	i++;
      k = 0;
      if ((my_list[j] = malloc(sizeof(char) * sizetab(str, c, i) + 2)) == NULL)
        return (NULL);
      while (str[i] != c && str[i] != 0)
          my_list[j][k++] = str[i++];
      if (c == ':')
        my_list[j][k++] = '/';
      my_list[j++][k] = 0;
      i++;
    }
  my_list[j] = 0;
  return (my_list);
}
