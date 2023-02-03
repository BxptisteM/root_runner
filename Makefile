##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC     =	test.c	\


OBJ =   $(SRC:.c=.o)

NAME =  Root_runner

CFLAGS = -W -Wall -Wextra

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:    $(NAME)

$(NAME):    $(OBJ)
		gcc -o $(NAME) $(SRC) $(CSFML)
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
