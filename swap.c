void    my_swap(int *a, int *b)
{
  int   c;

  c = *a;
  *a = *b;
  *b = c;
}

int     my_getnbr(char *str)
{
  int   nb;
  int   i;

  i = 0;
  nb = 0;
  while (str[i] != 0)
    {
      nb = (nb * 10) + (str[i] - 48);
      i++;
    }
  return (nb);
}
