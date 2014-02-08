/*
** my_put.c for  in /home/bauwen_j/rendu/103architecte
** 
** Made by bauwens
** Login   <bauwen_j@epitech.net>
** 
** Started on  Tue Dec 10 17:52:12 2013 bauwens
** Last update Tue Dec 10 17:55:40 2013 bauwens
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      write(1, &str[i], 1);
      i++;
    }
}
