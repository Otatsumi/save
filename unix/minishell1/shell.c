/*
** shell.c for  in /home/bauwen_j/rendu/psu/PSU_2013_minishell1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sun Jan 26 14:17:21 2014 bauwen_j
** Last update Sun Jan 26 14:17:21 2014 bauwen_j
*/
#include <stdlib.h>
#include <unistd.h>
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

char    *chemin(char *command, char *path)
{
  char  *str;
  int   i;
  int   j;

  str = malloc((my_strlen(command) + my_strlen(path) + 1) * sizeof(char));
  if (str == NULL || command == NULL)
    return (NULL);
  i = 0;
  while (path[i] != 0)
    {
      str[i] = path[i];
      i++;
    }
  j = 0;
  while (command[j] != 0)
    {
      str[i] = command[j];
      i++;
      j++;
    }
  str[i] = 0;
  return (str);
}

void	my_exec(char **com, char **path, char **env)
{
  char	*str;
  int	i;

  i = 0;
  while (path != NULL && path[i] != 0)
    {
      if ((str = chemin(com[0], path[i])) == NULL)
 	return ;
      if (access(str, F_OK) != -1)
 	{
	  my_execve(str, com, env);
 	  return ;
 	}
      i++;
    }
  if (access(com[0], F_OK) != -1)
    my_execve(com[0], com, env);
  else
    my_put("error : file don't exist\n");
}

int             main(int ac, char **argv, char **env)
{
  t_list        data;
  char          *str;

  data = the_data(env);
  while (ac != 0)
    {
      my_put("HALL 9000 > ");
      if ((str = get_next_line(0)) == NULL)
	return (0);
      if (str[0] != 0)
	{
	  if ((argv = my_sort_wordtab(str, ' ')) != NULL)
	    {
	      if (check_builtins(argv, &data) == 1)
		my_exec(argv, data.path, data.envp);
	      argv = NULL;
	    }
	}
      free(str);
    }
  return (0);
}
