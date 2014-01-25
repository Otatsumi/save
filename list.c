/*
** list.c for  in /home/bauwen_j/rendu/lib
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sat Jan 25 15:52:22 2014 bauwen_j
** Last update Sat Jan 25 15:52:22 2014 bauwen_j
*/

#include <stdlib.h>
#include "my.h"

void	my_error()
{
  my_putstr("error : impossible to create list of tab\n");
  exit(0);
}

t_circle	*circle_list(char **tab)
{
  int           i;
  t_circle	*arg;
  t_circle      *last;
  t_circle      *first;

  i = 1;
  if ((arg = malloc(sizeof(t_circle))) == NULL)
    my_error();
  arg->data = tab[0];
  arg->next = arg;
  arg->prev = arg;
  first = arg;
  while (tab[i] != 0)
    {
      if ((arg->next = malloc(sizeof(t_circle))) == NULL)
	my_error();
      arg->next->data = tab[i];
      last = arg;
      arg = arg->next;
      arg->next = first;
      arg->prev = last;
      i++;
    }
  return (arg);
}
