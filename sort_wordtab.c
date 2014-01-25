/*
** sort_wordtab.c for  in /home/bauwen_j/rendu/lib
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sat Jan 25 15:15:04 2014 bauwen_j
** Last update Sat Jan 25 15:15:04 2014 bauwen_j
*/

#include <stdlib.h>

int	sizeword(char *str, char c, int i)
{
  while (str[i] != 0 && str[i] != c)
    i++;
  return (i);
}

int	sizetab(char *str, char c)
{
  int	i;
  int	nbw;

  i = 0;
  nbw = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	nbw++;
      i++;
    }
  return (nbw);
}

char	**my_sort_wordtab(char *str, char c)
{
  int	i;
  int	j;
  int	k;
  char	**my_list;

  j = 0;
  i = 0;
  if ((my_list = malloc((sizetab(str, c) + 1) * sizeof(char*))) == NULL)
    return (NULL);
  while (str[i] != 0 && i < my_strlen(str))
    {
      k = 0;
      if ((my_list[j] = malloc(sizeof(char) * sizeword(str, c, i) + 2)) == NULL)
	return (NULL);
      while (str[i] != c && str[i] != 0)
	  my_list[j][k++] = str[i++];
      if (c == ':')
	my_list[j][k++] = '/';
      my_list[j][k] = 0;
      j++;
      i++;
    }
  my_list[j] = 0;
  return (my_list);
}
