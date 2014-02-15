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
