##
## Makefile for  in /home/bauwen_j/rendu/103architecte
## 
## Made by bauwens
## Login   <bauwen_j@epitech.net>
## 
## Started on  Tue Dec 10 17:43:20 2013 bauwens
## Last update Wed Dec 11 17:02:36 2013 bauwens
##

NAME	= 103architecte

SRC	= architecte.c \
	  my_put.c \
	  calcul.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -W -Wall

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.phony: all clean fclean re
