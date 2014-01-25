NAME    = lib

SRC     = main.c \
          my_put.c \
          my_swap.c

OBJ     = $(SRC:.c=.o)

CFLAGS  = -W -Wall

all: $(NAME)

$(NAME): $(OBJ)
        cc -o $(NAME) $(OBJ)

clean:
        rm -f $(OBJ)

fclean: clean
        rm -f $(NAME)

re:     fclean all

.phony: all clean fclean re
