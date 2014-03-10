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

  if (access(chemin, X_OK) == -1)
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
