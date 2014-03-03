##
## Makefile for  in /home/broggi_t/projets/rush2
##
## Made by broggi_t
## Login   <broggi_t@epitech.eu>
##
## Started on  Fri 28 Feb 15:52:28 2014 broggi_t
## Last update Sun Mar  2 21:52:42 2014 
##

SRCS	= srcs/algo.c \
	  srcs/check.c \
	  srcs/display.c \
	  srcs/get_next_line.c \
	  srcs/grid.c \
	  srcs/main.c \
	  srcs/my_str.c \
	  srcs/my_strcmp.c \
	  srcs/square_per_square.c

OBJS	= $(SRCS:.c=.o)

NAME	= sudoki-bi

CC	= cc

CFLAGS	+= -W -Wall -Wextra -pedantic -ansi
CFLAGS	+= -I includes/

RM	= rm -f

CP	= cp -f

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)
	$(CP) $(NAME) bin/$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME) bin/$(NAME)

re:	fclean all

.PHONY:	all clean fclean re
