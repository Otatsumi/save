##
## Makefile for  in /home/bauwen_j/rendu/lib
## 
## Made by bauwen_j
## Login   <bauwen_j@epitech.eu>
## 
## Started on  Sat Jan 25 14:46:37 2014 bauwen_j
## Last update Sat Jan 25 14:46:37 2014 bauwen_j
##

NAME    = lib

SRC     = main.c \
          put.c \
          swap.c \
	  fct_str.c

OBJ     = $(SRC:.c=.o)

CFLAGS  = -W -Wall -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.phony: all clean fclean re
