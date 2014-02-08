/*
** my_setenv.c for  in /home/bauwen_j/rendu/psu/PSU_2013_minishell1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sun Jan 26 14:17:05 2014 bauwen_j
** Last update Sun Jan 26 14:17:05 2014 bauwen_j
*/

#include <stdlib.h>
#include "get_next_line.h"

char    **new_env(char *line, char **tab)
{
  char  **ndata;
  int   i;

  i = 0;
  while (tab[i] != 0)
    i++;
  if ((ndata = malloc((i + 2)* sizeof(char *))) == NULL)
    return (tab);
  i = 0;
  while (tab[i] != 0)
    {
      ndata[i] = tab[i];
      i++;
    }
  ndata[i] = line;
  ndata[i + 1] = 0;
  return (ndata);
}

char    *add_line(char **com)
{
  char  *line;
  int   i;
  int   j;
  int   k;

  i = my_strlen(com[0]) + my_strlen(com[1]) + my_strlen(com[2]);
  if ((line = malloc((i + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 1;
  j = 0;
  while (com[i] != 0)
    {
      k = 0;
      while (com[i][k] != 0)
        line[j++] = com[i][k++];
      if (i == 1)
        line[j++] = '=';
      i++;
    }
  line[j] = 0;
  return (line);
}

char    **add_env(char **com, t_list *data)
{
  char  *line;
  int   i;

  i = 0;
  while (com[i] != 0)
    i++;
  if (i != 3)
    my_put("error setenv : too many or less argument\n");
  else
    {
      if ((line = add_line(com)) == NULL)
        return (data->envp);
      if ((i = my_match(com[0], data->envp)) != -1)
	data->envp[i] = line;
      else
        data->envp = new_env(line, data->envp);
    }
  if (my_match("PATH", com) != -1)
    data->path = the_path(data->envp);
  else if (my_match("HOME", com) != -1)
    data->home = the_home(data->envp);
  return (data->envp);
}
