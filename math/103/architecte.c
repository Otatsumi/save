/*
** architecte.c for  in /home/bauwen_j/rendu/103architecte
** 
** Made by bauwens
** Login   <bauwen_j@epitech.net>
** 
** Started on  Tue Dec 10 17:47:20 2013 bauwens
** Last update Wed Dec 11 11:28:10 2013 bauwens
*/

#include "my.h"

int	check_nb(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
	return (1);
      i++;
    }
  return (0);
}

int	check_transfo(char *str)
{
  if (str[0] == 'T')
    return (0);
  if (str[0] == 'H')
    return (0);
  if (str[0] == 'R')
    return (0);
  if (str[0] == 'S')
    return (0);
  my_putstr("La transformation est inconnu...\n");
  return (1);
}

int	check_all(int ac, char **argv)
{
  int	i;

  i = 3;
  while (i <= ac - 1)
    {
      if (argv[i][0] == 'T' || argv[i][0] == 'H')
	{
	  if (argv[i + 1] == 0 || check_nb(argv[i + 1]) == 1)
	    return (1);
	  if (argv[i + 2] == 0 || check_nb(argv[i + 2]) == 1)
	    return (1);
	  i = i + 3;
	}
      else if (argv[i][0] == 'R' || argv[i][0] == 'S')
	{
	  if (argv[i + 1] == 0 || check_nb(argv[i + 1]) == 1)
	    return (1);
	  i = i + 2;
	}
      else
	return (1);
    }
  return (0);
}

int	check_error(int ac, char **argv)
{
  int	i;

  i = 3;
  if (check_nb(argv[1]) != 0 || check_nb(argv[2]) != 0)
    {
      my_putstr("argument  et/ou deux invalide...\n");
      return (1);
    }
  if (check_transfo(argv[i]) != 0)
    return (1);
  if (check_all(ac, argv) != 0)
    return (1);
  return (0);
}

int	main(int ac, char **argv)
{
  if (ac < 5)
    {
      my_putstr("Le nombre d'argument est insufisant...\n");
      return (0);
    }
  if (check_error(ac, argv) == 1)
    return (0);
  calc(ac, argv);
  return (0);
}
