##
## EPITECH PROJECT, 2022
## delivery
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	=	-Wall -Wextra -g3

CPPFLAGS	=	-I include/

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	fclean clean all re
