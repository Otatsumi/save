/*
** main.c for  in /home/bauwen_j/rendu/lib
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sat Jan 25 14:46:28 2014 bauwen_j
** Last update Sat Jan 25 14:46:28 2014 bauwen_j
*/

#include <stdlib.h>
#include "my.h"

int	main(int ac, char **argv)
{
  t_circle *tab;

  tab = circle_list(argv);  
  my_putstr("ok\n");
  while (1)
    {
      my_putstr(tab->data);
      tab = tab->next;
    }

  return (0);
}
