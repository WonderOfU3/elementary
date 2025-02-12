##
## EPITECH PROJECT, 2022
## delivery
## File description:
## Makefile
##

SRC	=	src/radix.c	\
		src/sort_command.c	\
		lib/my/my_swap.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putstr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_strlen.c	\
		lib/my/my_getnbr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I include/

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -g3 -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	fclean clean all re
