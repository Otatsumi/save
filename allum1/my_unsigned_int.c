/*
** my_unsigned_int.c for  in /home/bauwen_j/rendu/my_git/alum1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Tue Feb 11 11:56:03 2014 bauwen_j
** Last update Tue Feb 11 11:56:03 2014 bauwen_j
*/

int	check_nb(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] < 48 || str[i] > 57)
	return (-1);
      i++;
    }
  return (0);
}

int	my_unsigned_int(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  if (check_nb(str) == -1)
    return (-1);
  while (str[i] != 0)
    {
      nb = nb * 10 + str[i] - 48;
      i++;
    }
  return (nb);
}
