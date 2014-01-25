/*
** fct_str.c for  in /home/bauwen_j/rendu/lib
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sat Jan 25 14:47:11 2014 bauwen_j
** Last update Sat Jan 25 14:47:11 2014 bauwen_j
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *str1, char *str2)
{
  char	*buffer;
  int	i;
  int	j;

  i = my_strlen(str1);
  j = my_strlen(str2);
  buffer = malloc((i + j + 1) * sizeof(char));
  if (buffer == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str1[i] != 0)
    {
      buffer[i] = str1[i];
      i++;
    }
  while (str2[j] != 0)
    {
      buffer[i] = str2[j];
      i++;
      j++;
    }
  buffer[i] = 0;
  return (buffer);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != 0 && s2[i] != 0)
    i++;
  if (s1[i] == 0 && s2[i] == 0)
    return (0);
  else if (s1[i] == 0)
    return (-1);
  else
    return (1);
}
