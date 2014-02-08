/*
** fct_env.c for  in /home/bauwen_j/rendu/psu/PSU_2013_minishell1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sun Jan 26 14:14:18 2014 bauwen_j
** Last update Sun Jan 26 14:14:18 2014 bauwen_j
*/

#include <stdlib.h>
#include "get_next_line.h"

void    my_putenv(char **env)
{
  int   i;

  i = 0;
  while (env[i] != 0)
    {
      my_put(env[i++]);
      my_put("\n");
    }
}

char    **sous_line(char **env, int value)
{
  char  **envp;
  int   i;
  int   j;

  while (env[i] != 0)
    i++;
  if ((envp = malloc(i * sizeof(char *))) == NULL)
    return (env);
  i = 0;
  j = 0;
  while (env[i] != 0)
    {
      if (i == value)
        i++;
      else
        envp[j++] = env[i++];
    }
  envp[j] = 0;
  return (envp);
}

char    **sous_env(char **com, t_list *data)
{
  int   i;

  i = 0;
  while (com[i] != 0)
    i++;
  if (i != 2)
    {
      my_put("error unsetenv : number of argument invalid\n");
      return (data->envp);
    }
  if ((i = my_match(com[1], data->envp)) == -1)
    {
      my_put("error unsetenv : argument doesn't exist in environment\n");
      return (data->envp);
    }
  data->envp = sous_line(data->envp, i);
  if (my_match("PATH", com) != -1)
    data->path = NULL;
  else if (my_match("HOME", com) != -1)
    data->home = NULL;
  return (data->envp);
}

int     check_builtins(char **com, t_list *data)
{
  if (my_match("env", com) == 0)
    my_putenv(data->envp);
  else if (my_match("setenv", com) == 0)
    data->envp = add_env(com, data);
  else if (my_match("unsetenv", com) == 0)
    data->envp = sous_env(com, data);
  else if (my_match("cd", com) == 0)
    my_cd(com, data->home);
  else if (my_match("exit", com) == 0)
    exit(0);
  else
    return (1);
  return (0);
}
