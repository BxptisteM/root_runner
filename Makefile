##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC   = main.c		                 		\
		src/utils.c 						\
		src/menu.c							\
		src/in_game.c 						\
		lib/my/my_putstr.c					\
		lib/my/my_putstr_err.c 				\
		lib/my/my_putchar.c 				\
		lib/my/my_putchar_err.c 			\

OBJ =   $(SRC:.c=.o)

NAME =  root_runner

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) $(CSFML) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
