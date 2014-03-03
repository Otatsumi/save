/*
** sudo.h for  in /home/broggi_t/projets/rush2/includes
** 
** Made by 
** Login   <broggi_t@epitech.net>
** 
** Started on  Fri Feb 28 20:31:12 2014 
** Last update Sun Mar  2 21:47:33 2014 
*/

#ifndef SUDO_H_
# define SUDO_H_

# define SUCCESS	0
# define FAILURE	-1
# define MORE		11

# define SEPARATOR	' '
# define SIDE		'|'
# define TOP		'-'
# define LINE_SIZE	20

# define INVALID_LINE	"An invalid line has been found\n"
# define INVALID_GRID	"The grid is impossible to solve\n"

/*
** algo.c
*/
int		algo(char **map);

/*
** check.c
*/
int		check_col(int x, int value, char **map);
int		check_line(int y, int value, char **map);
int		check_square(int x, int y, int value, char **map);
int		check_all(int x, int y, int value, char **map);
int		get_value(int x, int y, char **map);

/*
** display.c
*/
int		display(char **map, char color);

/*
** grid.c
*/
char		**get_grid();

/*
** square_per_square.c
*/
int		check_per_square(char **map);

#endif /* !SUDO_H_ */
