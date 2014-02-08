/*
** calcul.c for  in /home/bauwen_j/rendu/103architecte
** 
** Made by bauwens
** Login   <bauwen_j@epitech.net>
** 
** Started on  Wed Dec 11 10:54:59 2013 bauwens
** Last update Wed Dec 11 17:03:00 2013 bauwens
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"

t_result	translation(t_result res, t_valcalc nb)
{
  double	x;
  double	y;

  x = nb.x + res.x;
  y = nb.y + res.y;
  res.x = x;
  res.y = y;
  return (res);
}

t_result	homothesie(t_result res, t_valcalc nb)
{
  double	x;
  double	y;

  x = nb.x * res.x;
  y = nb.y * res.y;
  res.x = x;
  res.y = y;
  return (res);
}

t_result	check_2_op(t_result res, char tcalcul, char *nb1, char *nb2)
{
  t_valcalc	nb;

  if (nb2 == 0)
    {
      my_putstr("deuxiemenombre invalide\n");
      return (res);
    }
  if (check_nb(nb1) == 1 || check_nb(nb2) == 1)
    {
      my_putstr("argument non valide, nombre uniquement...\n");
      return (res);;
    }
  nb.x = atoi(nb1);
  nb.y = atoi(nb2);
  if (tcalcul == 'T')
    res = translation(res, nb);
  else
    res = homothesie(res, nb);
  return (res);
}

t_result	rotation(t_result res, t_valcalc nb)
{
  double	x;
  double	y;
  double	ang;

  ang = nb.a * (M_PI/180);
  x = (cos(ang) * res.x) - (sin(ang) * res.y);
  y = (sin(ang) * res.x) + (cos(ang) * res.y);
  res.x = x;
  res.y = y;
  return (res);
}

t_result	symetrie(t_result res, t_valcalc nb)
{
  double	x;
  double	y;
  double	ang;

  ang = nb.a * (M_PI/180);
  x = (cos(2 * ang) * res.x) + (sin(2 * ang) * res.y);
  y = (sin(2 * ang) * res.x) - (cos(2 * ang) * res.y);
  res.x = x;
  res.y = y;
  return (res);
}

t_result	check_1_op(t_result res, char tcalcul, char *nb)
{
  t_valcalc n;

  if (check_nb(nb) == 1)
    {
      my_putstr("argument non valide, nombre uniquement...\n");
      return (res);
    }
  if (nb == 0)
    {
      my_putstr("argument invalide...\n");
      return (res);
    }
  n.a = atoi(nb);
  if (tcalcul == 'R')
    res = rotation(res, n);
  else if (tcalcul == 'S')
    res = symetrie(res, n);
  else
    my_putstr("transformation inconnu...\n");
  return (res);
}

void		calc(int ac, char **argv)
{
  int		i;
  t_pointb	cpa;
  t_result	res;

  cpa.x = atoi(argv[1]);
  cpa.y = atoi(argv[2]);
  res.x = cpa.x;
  res.y = cpa.y;
  i = 3;
  printf("(%d,%d)\n", cpa.x, cpa.y);
  while (i < ac)
    {
      if (argv[i][0] == 'T' || argv[i][0] == 'H')
	{
	  res = check_2_op(res, argv[i][0], argv[i + 1], argv[i + 2]);
	  i = i + 3;
	}
      else if (argv[i][0] == 'S' || argv[i][0] == 'R')
	{
	  res = check_1_op(res, argv[i][0], argv[i + 1]);
	  i = i + 2;
	}
      else
	{
	  my_putstr(argv[i]);
	  my_putstr("error: transformation inconnu...\n");
	  i = i + ac;
	}
    }
  printf("(%F,%F)\n", res.x, res.y);
  return;
}
