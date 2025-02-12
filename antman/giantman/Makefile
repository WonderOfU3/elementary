##
## EPITECH PROJECT, 2023
## antman_proj
## File description:
## Makefile
##

SRC	=	src/main.c								\
		src/decompress_ppm.c	 				\
		../lib/my/load_file_in_mem.c			\
		../lib/my/my_putstr.c 					\
		../lib/my/my_put_nbr.c 					\
		../lib/my/my_strcmp.c 					\
		../lib/my/my_strlen.c					\
		../lib/my/my_putchar.c 					\

OBJ	=	$(SRC:.c=.o)

NAME	=	giantman

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I ../include/

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -g3 -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	fclean clean all re
