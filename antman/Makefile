##
## EPITECH PROJECT, 2023
## antman
## File description:
## Makefile
##

SRC	=	antman/src/main.c							\
		antman/src/compress_ppm.c					\
		lib/my/load_file_in_mem.c					\
		lib/my/my_putstr.c 							\
		lib/my/my_strcmp.c 							\
		lib/my/my_strlen.c							\
		lib/my/my_str_to_word_array.c 				\
		lib/my/my_getnbr.c 							\
		lib/my/my_putchar.c 						\
		lib/my/handle_errors.c 						\

SRC2 =	giantman/src/main.c						\
		giantman/src/decompress_ppm.c	 		\
		lib/my/load_file_in_mem.c				\
		lib/my/my_putstr.c 						\
		lib/my/my_put_nbr.c 					\
		lib/my/my_strcmp.c 						\
		lib/my/my_strlen.c						\
		lib/my/my_putchar.c 					\
		lib/my/handle_errors.c 					\

OBJ	=	$(SRC:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

NAME	=	antman/antman

NAME2	=	giantman/giantman

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I include/

all:	$(OBJ) $(OBJ2)
		gcc -g3 -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS)
		gcc -g3 -o $(NAME2) $(SRC2) $(CFLAGS) $(CPPFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)

re:	fclean all

.PHONY:	fclean clean all re
