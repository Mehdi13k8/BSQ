##
## EPITECH PROJECT, 2018
## bsq
## File description:
## mehdi
##

SRC	=	main.c			\
		str_to_tab.c		\
		squarer.c		\
		aff.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all: 		$(NAME)

$(NAME):	$(OBJ)
		gcc $(SRC) -o $(NAME) -Wall -Werror -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
