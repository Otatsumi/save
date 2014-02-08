##
## Makefile for makefile in /home/bauwen_j/rendu/Rush1
## 
## Made by bauwens
## Login   <bauwen_j@epitech.net>
## 
## Started on  Sun Dec 15 10:01:42 2013 bauwens
## Last update Sun Dec 15 10:01:44 2013 bauwens
##

NAME	= encodeur

NAME2	= décodeur

SRC	= morse.c \
	  my_put.c \
	  code_m.c \
	  get_next_line.c

SRC2	= unmorse.c \
	  code_m.c \
	  my_put.c \
	  corres.c \
	  get_next_line.c

OBJ	= $(SRC:.c=.o)

OBJ2	= $(SRC2:.c=.o)

CFLAGS	= -W -Wall

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ)

$(NAME2): $(OBJ2)
	cc -o $(NAME2) $(OBJ2)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)

re:	fclean all

.PHONY: all clean fclean re
