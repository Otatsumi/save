/*
** builtins.c for  in /home/bauwen_j/rendu/my_git/PSU_2013_minishell2
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Thu Feb 27 13:52:26 2014 bauwen_j
** Last update Thu Feb 27 13:52:26 2014 bauwen_j
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

void    my_cd(char **com, char *home)
{
  char  *str;
  int   i;
  int   j;

  if (com[1] == 0)
    str = &home[5];
  else
    {
      if ((str = malloc(my_strlen(com[1]) + 2 * sizeof(char))) == NULL)
        return;
      j = 0;
      if (com[1][0] == '/')
        i = 0;
      else
        {
          i = 2;
          str[0] = '.';
          str[1] = '/';
        }
      while (com[1][j] != 0)
        str[i++] = com[1][j++];
      str[i] = 0;
    }
  if (chdir(str) == -1)
    my_put("error : cd failed\n");
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
