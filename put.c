#include <unistd.h>

void    my_putchar(char c)
{
  write(1, &c, 1);
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

void    my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void    my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb > 9)
      my_put_nbr(nb / 10);
  my_putchar((nb % 10) + 48);
}

