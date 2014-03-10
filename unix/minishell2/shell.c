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
#include "get_next_line.h"

int             main(int ac, char **argv, char **env)
{
  t_list        data;
  char		*buff;
  char          *str;

  data = the_data(env);
  while (ac != 0)
    {
      my_put("HALL 9000 > ");
      if ((str = get_next_line(0)) == NULL)
	return (0);
      if (str[0] != 0)
	{
	  if (check_adv_fct(str, &data) == 1
	      && (argv = my_sort_wordtab(str, ' ')) != NULL)
	    {
	      if (check_builtins(argv, &data) == 1)
		if ((buff = my_access(argv, data.path)) != NULL)
		  my_execve(buff, argv, data.envp);
	      argv = NULL;
	    }
	}
      free(str);
    }
  return (0);
}
