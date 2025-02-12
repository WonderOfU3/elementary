##
## EPITECH PROJECT, 2023
## antman
## File description:
## Makefile
##

SRC	=	generator/src/main.c	\
		generator/src/map.c		\

SRC2 =	solver/src/main.c					\
		solver/src/map.c					\
		solver/src/my_str_to_word_array.c	\
		solver/src/my_strlen.c				\
		solver/src/solve.c					\

OBJ	=	$(SRC:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

NAME	=	generator/generator

NAME2	=	solver/solver

CFLAGS	=	-I include/

CPPFLAGS	=	-Wall -Wextra

all:	$(OBJ) $(OBJ2)
		gcc -g3 -o $(NAME) $(SRC) $(CFLAGS)
		gcc -g3 -o $(NAME2) $(SRC2) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)

re:	fclean all

.PHONY:	fclean clean all re
