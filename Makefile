##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	 =	./src/main.c			\
		./src/workshop/add.c	\
		./src/workshop/del.c	\
		./src/workshop/sort.c	\
		./src/workshop/disp.c	\
		./src/put/my_putstr.c	\
		./src/put/my_put_nbr.c	\
		./src/put/my_putchar.c	\
		./src/my_strcmp.c		\
		./src/my_getnbr.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS  =       -Wall -Wextra -I ./include/ -g3

HEADER	=	my.h

NAME	=	organized

all:	$(NAME)
	$(CC) -o $(NAME) $(OBJ) -L./shell -lshell

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *~
	rm -f *.gc*
	rm -f *.log

re:	fclean all

.PHONY:	all $(NAME) clean fclean re
