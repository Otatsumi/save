##
## Makefile for  in /home/bauwen_j/rendu/psu/PSU_2013_minishell1
## 
## Made by bauwen_j
## Login   <bauwen_j@epitech.eu>
## 
## Started on  Sun Jan 26 14:13:05 2014 bauwen_j
## Last update Sun Jan 26 14:13:05 2014 bauwen_j
##

NAME    = mysh

SRC     = shell.c \
          my_exec.c \
	  multi_com.c \
	  builtins.c \
          my_put.c \
          fct_data.c \
          fct_env.c \
          fct_setenv.c \
	  fct_direction.c \
          getnext.c

OBJ     = $(SRC:.c=.o)

CFLAGS  = -W -Wall -Wextra -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.phony: all clean fclean re
