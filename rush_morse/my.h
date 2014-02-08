/*
** my.h for my.h in /home/bauwen_j/rendu/Rush1
** 
** Made by bauwens
** Login   <bauwen_j@epitech.net>
** 
** Started on  Sun Dec 15 10:02:50 2013 bauwens
** Last update Sun Dec 15 10:02:53 2013 bauwens
*/

#ifndef MY_H_
# define MY_H_
# define ALPHA ".abcdefghijklmnopqrstuvwxyz123456789"

void	my_putstr(char *str);
void	my_putchar(char c);
int	my_strlen(char *str);
int	corres(char *buffer, char *code);
char	**tab_corres();
int	stop_carac(char *str, int j);

#endif /* !MY_H_ */
