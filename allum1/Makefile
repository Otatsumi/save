##
## Makefile for  in /home/bauwen_j/rendu/my_git/test
## 
## Made by bauwen_j
## Login   <bauwen_j@epitech.eu>
## 
## Started on  Fri Feb  7 17:25:06 2014 bauwen_j
## Last update Fri Feb  7 17:25:06 2014 bauwen_j
##

NAME    = Allum1

SRC     = main.c \
	  battle.c \
	  ia.c \
	  getnext.c \
	  check.c \
	  puttab.c \
	  my_unsigned_int.c \
	  2player.c \
	  fort_boyard.c \
	  ia_fort.c \
	  put.c

OBJ     = $(SRC:.c=.o)

CFLAGS  = -W -Wall -Wextra -Wpointer-sign

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.phony: all clean fclean re
