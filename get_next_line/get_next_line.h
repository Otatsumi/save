/*
** get_next_line.h for get_next_line in /home/bauwen_j/rendu/CPE_2013_get_next_line
** 
** Made by bauwens
** Login   <bauwen_j@epitech.net>
** 
** Started on  Sat Nov 23 12:26:25 2013 bauwens
** Last update Mon Nov 25 23:06:33 2013 bauwens
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# define	SIZE_READ	(84)

int	size(char *str);
char	*my_newbuf(char *buffer, char *str);
int	size_newbuf(int last_n, char *buffer);
char	*aff_str(char *buffer, int nb_read);
char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
