/*
** shell3.c for  in /home/bauwen_j/rendu/my_git/PSU_2013_minishell2
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Wed Feb 26 16:43:23 2014 bauwen_j
** Last update Wed Feb 26 16:43:23 2014 bauwen_j
*/

#include <stdlib.h>
#include "get_next_line.h"

void	my_error()
{
  exit(0);
}

int	my_str_match(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	return (0);
      i++;
    }
  return (-1);
}

void	my_multi_com(char *com, t_list *data)
{
  char	**tab;
  char	**ltab;
  char	*buff;
  int	i;

  if ((tab = my_sort_wordtab(com, ';')) == NULL)
    my_error();
  i = 0;
  while (tab[i] != 0)
    {
      if (check_adv_fct(tab[i], data) == 1)
	{
	  if ((ltab = my_sort_wordtab(tab[i], ' ')) != NULL)
	    {
	      if ((buff = my_access(ltab, data->path)) != NULL)
		my_execve(buff, ltab, data->envp);
	      ltab = NULL;
	    }
	}
      i++;
    }
}

int	check_adv_fct(char *com, t_list *data)
{
  if (my_str_match(';', com) == 0)
    {
      my_multi_com(com, data);
      return (0);
    }
  if (my_str_match('>', com) == 0)
    {
      my_gere_dir(com, data);
      return (0);
    }
  return (1);
}
