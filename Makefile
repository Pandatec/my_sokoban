##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

CC	=	gcc

NAME	=	my_sokoban

SRC	=	src/my_sokoban.c		\
		src/my_strlen.c			\
		src/direction.c			\
		src/direction_o.c		\
		src/win_or_lose.c		\


OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

CFLAGS	=	-Werror -Wextra -Wall -lncurses -Iinlcude -lm -g3

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

tests_run:
	$(CC) $(SRC) Test/*.c --coverage -lcriterion -I./include
	./a.out


clean:
		$(RM) $(OBJ)
		$(RM) vgcore.*
		$(RM) *.gcno

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:		all clean fclean re
