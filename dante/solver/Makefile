##
## EPITECH PROJECT, 2023
## antman_proj
## File description:
## Makefile
##

SRC	=	src/main.c					\
		src/map.c					\
		src/my_str_to_word_array.c	\
		src/my_strlen.c				\
		src/solve.c					\

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

CFLAGS	=	-I ../include/

CPPFLAGS	=	-Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -g3 -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	fclean clean all re
