/*
** ia_fort.c for  in /home/bauwen_j/rendu/finish/save/allum1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sat Feb 15 09:48:09 2014 bauwen_j
** Last update Sat Feb 15 09:48:09 2014 bauwen_j
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

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

char	*ia_fort(char *allum)
{
  char	nbr[2];
  int	nb_allum;
  int	nb;

  nb_allum = my_strlen(allum);
  nb = (nb_allum - 1) % 4;
  nbr[0] = nb + 48;
  nbr[1] = 0;
  allum = fort_sous(allum, nbr);
  return (allum);
}

void	fort_2p(char *str)
{
  char	*allum;
  int	nb_a;

  my_putstr("the battle beggin for 2 player\n");
  nb_a = my_strlen(str);
  while (nb_a != 0)
    {
      my_putstr(str);
      my_putstr("\nround player 1\n");
      allum = fort_allum(str);
      str = fort_sous(str, allum);
      nb_a = my_strlen(str);
      if (nb_a == 0)
	{
	  my_putstr("player 1 loose, player 2 win\n");
	  exit(0);
	}
      my_putstr(str);
      my_putstr("\nround player 2\n");
      allum = fort_allum(str);
      str = fort_sous(str, allum);
      nb_a = my_strlen(str);
    }
  my_putstr("player 2 loose, player 1 win\n");
}

int	check_play()
{
  char	*str;
  int	i;

  str = NULL;
  i = 0;
  while (str == NULL || i <= 0 || i > 2)
    {
      my_putstr("\nenter 1 for 1 player or 2 for 2 player\n");
      if ((str = get_next_line(0)) == NULL)
	my_quit("error : get_next_line failed\n");
      i = my_unsigned_int(str);
    }
  return (i);
}
