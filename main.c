#include "my.h"

int     main()
{
  my_putchar(42);
  my_putchar('\n');
  my_putstr("42");
  my_putchar('\n');
  my_put_nbr(42);
  my_putchar('\n');
  printf("%d\n", my_getnbr("42"));

  return (0);
}
