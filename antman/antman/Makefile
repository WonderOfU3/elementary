##
## EPITECH PROJECT, 2023
## antman_proj
## File description:
## Makefile
##

SRC	=	src/main.c							\
		src/compress_ppm.c					\
		../lib/my/load_file_in_mem.c		\
		../lib/my/my_putstr.c 				\
		../lib/my/my_strcmp.c 				\
		../lib/my/my_strlen.c				\
		../lib/my/my_str_to_word_array.c 	\
		../lib/my/my_getnbr.c 				\
		../lib/my/my_putchar.c 				\

OBJ	=	$(SRC:.c=.o)

NAME	=	antman

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I ../include/

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -g3 -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS)

clean:
	rm -f $(OBJ)
	rm -f ../file

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	fclean clean all re
