/*
** fct_direction.c for  in /home/bauwen_j/rendu/my_git/PSU_2013_minishell2
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Thu Feb 27 14:33:14 2014 bauwen_j
** Last update Thu Feb 27 14:33:14 2014 bauwen_j
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "get_next_line.h"

void	my_exec_dir(char *chemin, char **str, int param, t_list *data)
{
  char	**tab;
  char	**file;
  pid_t	pid;
  int	status;
  int	fd;

  file = my_sort_wordtab(str[1], ' ');
  if ((tab = my_sort_wordtab(str[0], ' ')) == NULL || file == NULL)
    return ;
  if ((pid = fork()) == 0)
    {
      fd = open(file[0], param, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
      if (fd == -1 || dup2(fd, 1) == -1)
	exit(0);
      if (execve(chemin, tab, data->envp))
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

void	my_dir(char **str, int param, t_list *data)
{
  char	*chemin;
  char	**com;
  int	i;

  if ((com = my_sort_wordtab(str[0], ' ')) == NULL)
    return ;
  if ((chemin = my_access(com, data->path)) == NULL)
    return ;
  if (access(chemin, R_OK | X_OK) == -1)
    return ;
  i = 0;
  while (str[i + 1] != 0)
    i++;
  if (access(str[i], F_OK) == -1)
    my_exec_dir(chemin, str, param, data);
  else if (access(str[i], W_OK) != -1)
    my_exec_dir(chemin, str, param, data);
  return ;
}

void	my_gere_dir(char *str, t_list *data)
{
  char	**tab;
  int	param;
  int	i;

  i = 0;
  while (str[i] != '>')
    i++;
  if (str[i + 1] == '>')
    param = O_CREAT | O_APPEND | O_WRONLY;
  else
    param = O_CREAT | O_TRUNC | O_WRONLY;
  if ((tab = my_sort_wordtab(str, '>')) == NULL)
    return ;
  my_dir(tab, param, data);
}
