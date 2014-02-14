/*
** my.h for  in /home/bauwen_j/rendu/my_git/test
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Fri Feb  7 17:17:46 2014 bauwen_j
** Last update Fri Feb  7 17:17:46 2014 bauwen_j
*/

#ifndef MY_H_
# define MY_H_

void	battle(char **tab, int nb_allum);
void    my_putchar(char c);
int     my_strlen(char *str);
void    my_putstr(char *str);
void	my_put_tab(char **tab);
int	my_size_tab(char **tab);
int	al_tab(char **tab);
int	check_line(char **tab, char *line);
int	check_allum(char **tab, char *line, char *allum);
char	**sous_line(char **tab, int l);
char	*sous_allum(int a, int sizel);
char	**ia(char **tab);
int	my_unsigned_int(char *str);
char	**new_tab(char **tab, char *line, char *allum);
void	my_quit(char *str);
void	two_player(char **tab, int nb_a);
char	*nb_allum(char **tab, char *line);
char	*nb_line(char **tab);
void	fort_mode();

#endif /* !MY_H_ */
