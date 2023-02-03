##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC   = my_hunter.c                 		\
		source/start.c	 					\
		source/in_game.c 					\
		source/sprites_managment.c			\
		source/my_putstr.c					\
		source/my_putstr_err.c 				\
		source/my_putchar.c 				\
		source/my_putchar_err.c 			\

OBJ =   $(SRC:.c=.o)

NAME =  my_hunter

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) $(CSFML) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
