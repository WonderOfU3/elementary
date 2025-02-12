##
## EPITECH PROJECT, 2023
## stumper
## File description:
## Makefile
##

NAME 	=	lem_in

CC	=	gcc

SRC     =	src/main.c \
		src/fonctions.c \
		src/my_strword_array.c \
		src/parsing.c \
		src/matrix.c \
		src/algo.c \

OBJ     =	$(SRC:.c=.o)

CFLAGS	=	-I./include

CPPFLAGS = -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean fclean re all
