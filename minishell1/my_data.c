/*
** my_data.c for  in /home/bauwen_j/rendu/psu/PSU_2013_minishell1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sun Jan 26 14:13:30 2014 bauwen_j
** Last update Sun Jan 26 14:13:30 2014 bauwen_j
*/

#include <stdlib.h>
#include "get_next_line.h"

int     my_match(char *search, char **tab)
{
  int   i;
  int   j;

  i = 0;
  while (tab[i] != 0)
    {
      j = 0;
      while (search[j] == tab[i][j] && search[j] != 0)
        j++;
      if (search[j] == 0)
          return (i);
      i++;
    }
  return (-1);
}

char    **the_path(char **env)
{
  int   i;
  char  **path_list;

  if ((i = my_match("PATH=", env)) != -1)
    {
      path_list = my_sort_wordtab(&env[i][5], ':');
      return (path_list);
    }
  return (NULL);
}

char    *the_home(char **env)
{
  int   i;
  char  *home;

  if ((i = my_match("HOME=", env)) != -1)
    {
      home = (env[i]);
      return (home);
    }
  return (NULL);
}

t_list          the_data(char **env)
{
  t_list        data;

  if (env == NULL)
    {
      data.envp = env;
      data.path = NULL;
      data.home = NULL;
    }
  else
    {
      data.envp = env;
      data.path = the_path(env);
      data.home = the_home(env);
    }
  return (data);
}
