/*
** main.c for  in /home/bauwen_j/rendu/lib
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sat Jan 25 14:46:28 2014 bauwen_j
** Last update Sat Jan 25 14:46:28 2014 bauwen_j
*/

#include "my.h"

int     main()
{
  char *buff;

  my_putchar(42);
  my_putchar('\n');
  my_putstr("42");
  my_putchar('\n');
  my_put_nbr(42);
  my_putchar('\n');
  printf("%d\n", my_getnbr("42"));

  buff = my_strcpy("coucou ", "le monde.");
  my_putstr(buff);
  my_putchar('\n');

  my_putnbr_base(42, "01");
  my_putchar('\n');
  my_putnbr_base(42, "0123456789");
  my_putchar('\n');
  my_putnbr_base(42, "0123456789ABCDEF");
  my_putchar('\n');
  return (0);
}
