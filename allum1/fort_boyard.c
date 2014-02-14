/*
** fort_boyad.c for  in /home/bauwen_j/rendu/finish/save/allum1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Fri Feb 14 15:52:46 2014 bauwen_j
** Last update Fri Feb 14 15:52:46 2014 bauwen_j
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

int	check_fort_a(char *str, char *allum)
{
  int	nb_a;
  int	a;

  a = my_unsigned_int(allum);
  if (a < 1 || a > 3)
    {
      my_putstr("number of machstick is 1, 2 or 3 only\n");
      return (-1);
    }
  nb_a = my_strlen(str);
  if (a > nb_a)
    {
      my_putstr("number of machstick is to big\n");
      return (-1);
    }
  return (0);
}

char	*fort_allum(char *str)
{
  char	*allum;

  allum = NULL;
  while (allum == NULL || check_fort_a(str, allum) == -1)
    {
      my_putstr("\nenter the number of matchstick\n");
      if ((allum = get_next_line(0)) == NULL)
	my_quit("error : get_next_line failed\n");
    }
  return (allum);
}

char	*fort_sous(char *str, char *allum)
{
  char	*buff;
  int	i;
  int	j;

  i = my_strlen(str) - my_unsigned_int(allum);
  if ((buff = malloc(i * sizeof(char))) == NULL)
    my_quit("error : malloc failed\n");
  j = 0;
  while (j < i)
    {
      buff[j] = '|';
      j++;
    }
  buff[j] = 0;
  return (buff);
}

void	fort_battle(char *str)
{
  char	*allum;
  int	nb_a;

  my_putstr("the battle beggin for 1 player\n");
  nb_a = my_strlen(str);
  while (nb_a != 0)
    {
      my_putstr("\nround player\n");
      my_putstr(str);
      allum = fort_allum(str);
      str = fort_sous(str, allum);
      nb_a = my_strlen(str);
      if (nb_a == 0)
	{
	  my_putstr("you loose\n");
	  exit(0);
	}
      my_putstr("\nround ia\n");
      nb_a = my_strlen(str);
    }
  my_putstr("you win\n");
}

int	check_fort(char *str)
{
  int	i;

  i = my_unsigned_int(str);
  if (i >= 20 && i <= 60)
    return (0);
  else
    return (-1);
}

void	fort_mode()
{
  char	*allum;
  char	*str;
  int	i;

  str = NULL;
  while (str == NULL || check_fort(str) == -1)
    {
      my_putstr("enter the number of matchstick\n");
      if ((str = get_next_line(0)) == NULL)
	my_quit("error : get_next_line failed\n");
    }
  if ((allum = malloc(my_unsigned_int(str) * sizeof(char))) == NULL)
    my_quit("error : malloc failed\n");
  i = 0;
  while (i < my_unsigned_int(str))
    {
      allum[i] = '|';
      i++;
    }
  allum[i] = 0;
  fort_battle(allum);
}
