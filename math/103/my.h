/*
** my.h for  in /home/bauwen_j/rendu/103architecte
** 
** Made by bauwens
** Login   <bauwen_j@epitech.net>
** 
** Started on  Wed Dec 11 10:56:09 2013 bauwens
** Last update Wed Dec 11 11:37:40 2013 bauwens
*/

#ifndef MY_H_
# define MY_H_

typedef struct s_pointb
{
  int		x;
  int		y;
}		t_pointb;

typedef struct s_valcalc
{
  int		x;
  int		y;
  double	a;
}		t_valcalc;

typedef struct s_result
{
  double	x;
  double	y;
}		t_result;

t_result	translation(t_result res, t_valcalc nb);
t_result	homothesie(t_result res, t_valcalc nb);
t_result	check_2_op(t_result res, char tcalcul, char *nb1, char *nb2);
t_result	rotation(t_result res, t_valcalc nb);
t_result	symetrie(t_result res, t_valcalc nb);
t_result	check_1_op(t_result res, char tcalcul, char *nb);
void		calc(int ac, char **argv);
void		my_putstr(char *str);
int		check_nb(char *str);
int		check_transfo(char *str);
int		check_all(int ac, char **argv);
int		check_error(int ac, char **argv);

#endif /* !MY_H_ */
