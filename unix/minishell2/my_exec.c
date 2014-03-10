/*
** shell2.c for  in /home/bauwen_j/rendu/psu/PSU_2013_minishell1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sun Jan 26 14:17:38 2014 bauwen_j
** Last update Sun Jan 26 14:17:38 2014 bauwen_j
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "get_next_line.h"

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

char    **my_com(char **command)
{
  char  **com;
  char  *str;
  int   i;
  int   j;

  if (command[0][0] == '/')
    {
      i = 0;
      j = 0;
      while (command[0][i] != 0)
        {
          if (command[0][i] == '/')
            j = i;
          i++;
        }
      j++;
      str = &command[0][j];
      com = command;
      com[0] = str;
      return (com);
    }
  else
    return (command);
}

void	my_execve(char *chemin, char **com, char **env)
{
  int	status;
  pid_t	pid;

  if (access(chemin, R_OK | X_OK) == -1)
    {
      my_put("error : execution not permited\n");
      return ;
    }
  if ((pid = fork()) == 0)
    {
      com = my_com(com);
      if (execve(chemin, com, env) == -1)
	{
	  my_put("error : execution failed\n");
	  exit(0);
	}
    }
  else
    {
      if (wait(&status) == -1)
	return ;
    }
}

char	*my_access(char **com, char **path)
{
  char	*str;
  int	i;

  i = 0;
  while (path != NULL && path[i] != 0)
    {
      if ((str = chemin(com[0], path[i])) == NULL)
 	return (NULL);
      if (access(str, F_OK) != -1)
	return (str);
      i++;
    }
  if (access(com[0], F_OK) != -1)
    return (str);
  my_put("error : file doesn't exist\n");
  return (NULL);
}
