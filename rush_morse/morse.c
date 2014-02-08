/*
** morse.c for morse in /home/bauwen_j/rendu/Rush1
** 
** Made by bauwens
** Login   <bauwen_j@epitech.net>
** 
** Started on  Sun Dec 15 10:02:20 2013 bauwens
** Last update Sun Dec 15 10:07:03 2013 bauwens
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

int	check_mess(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= '0' && str[i] <= '9') ||
	  str[i] == '.' ||
	  (str[i] >= 'a' && str[i] <= 'z') ||
	  (str[i] >= 'A' && str[i] <= 'Z'))
	  i++;
      else if (str[i] == '\n' && str[i + 1] == 0)
	return (0);
      else
	{
	  my_putstr("msg invalide\n");
	  return (1);
	}
    }
  return (0);
}

void	code_morse(char c, char **code)
{
  int	i;
  char	*str;

  i = 0;
  str = ALPHA;
  while (str[i] != 0)
    {
      if ((c == str[i]) || ((c + 32) == str[i]))
	{
	  my_putstr(code[i]);
	  return;
	}
      i++;
    }
}

void	aff_msg(char *str, char **code)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (i != 0 && str[i] != '\n')
	my_putstr("...");
      code_morse(str[i], code);
      i++;
    }
  my_putchar('\n');
  return;
}

int	main()
{
  char **code;
  char	*str;
  int	stop;

  stop = 0;
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
