/*
** unmorse.c for unmorse in /home/bauwen_j/rendu/Rush1
** 
** Made by bauwens
** Login   <bauwen_j@epitech.net>
** 
** Started on  Sun Dec 15 10:03:47 2013 bauwens
** Last update Sun Dec 15 10:05:54 2013 bauwens
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

int	check_mess(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '.' || str[i] == '-' || str[i] == '_')
	i++;
      else if (str[i] == '\n' && str[i + 1] == 0)
	return (0);
      else
	{
	  my_putstr("code morse invalide\n");
	  return (1);
	}
    }
  return (0);
}

char	*morse_code(char *str, int i, int j)
{
  char	*buffer;
  int	k;

  if ((buffer = malloc((j - i + 1) * sizeof(char))) == NULL)
    return (NULL);
  k = 0;
  while (i < j)
    {
      if (str[i] == '\n')
	i = j + 1;
      else
	{
	  buffer[k] = str[i];
	  i++;
	  k++;
	}
    }
  buffer[k] = 0;
  return (buffer);
}

void	aff_buffer(char *buffer, char **code)
{
  char	*str;
  int	i;

  i = 0;
  str = ALPHA;
  while (code[i] != 0)
    {
      if (corres(buffer, code[i]) == 0)
	{
	  my_putchar(str[i]);
	  return;
	}
      i++;
    }
  my_putstr("message morse invalide!!!\n");
  return;
}

void	aff_msg(char *str, char **code)
{
  int	j;
  int	i;
  char	*buffer;

  j = 0;
  i = 0;
  while (str[i] != 0)
    {
      while (stop_carac(str, j) == 0 && str[j] != 0)
	j++;
      if ((buffer = morse_code(str, i, j)) == NULL)
	return;
      j = j + 3;
      i = j;
      aff_buffer(buffer, code);
      free(buffer);
    }
  my_putchar('\n');
}

int	main()
{
  char **code;
  char	*str;
  int stop;

  while (stop < 100000000)
    stop++;
  if ((str = get_next_line(0)) == NULL)
    return (0);
  if (check_mess(str) == 0)
    {
      if ((code = tab_corres()) == NULL)
	return (0);
      aff_msg(str, code);
    }
      free(code);
      free(str);
  return (0);
}
