/*
** corres for corres.c in /home/bauwen_j/rendu/Rush1
** 
** Made by bauwens
** Login   <bauwen_j@epitech.net>
** 
** Started on  Sun Dec 15 10:00:39 2013 bauwens
** Last update Sun Dec 15 10:06:37 2013 bauwens
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

int	corres(char *buffer, char *code)
{
  int	i;

  if (my_strlen(buffer) != my_strlen(code))
    return (1);
  i = 0;
  while (buffer[i] != 0)
    {
      if (buffer[i] != code[i])
	return (1);
      i++;
    }
  return (0);
}

int	stop_carac(char *str, int i)
{
  if (str[i] != '.')
    return (0);
  if (str[i + 1] == '.' && str[i + 2] == '.')
    return (1);
  return (0);
}
