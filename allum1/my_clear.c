/*
** my_clear.c for  in /home/bauwen_j/rendu/finish/save/allum1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Thu Feb 13 14:27:12 2014 bauwen_j
** Last update Thu Feb 13 14:27:12 2014 bauwen_j
*/

#include <curses.h>
#include <term.h>

int	my_term(char **env)
{
  int	i;

  i = 0;
  while (env[i] != 0)
    {
      if (env[i][0] == 'T'
	  && env[i][1] == 'E'
	  && env[i][2] == 'R'
	  && env[i][3] == 'M')
	return (i);
      i++;
    }
  return (-1);
}

char	*my_clear(char **env)
{
  char	*term;
  char	*clear;
  int	i;

  i = my_term(env);
  if (i < 0)
    return (NULL);
  else
    {
      term = env[i];
      if (tgetent(NULL, &term[5]) <= 0)
	return (NULL);
      clear = tgetstr("cl", NULL);
      return (clear);
    }
}
