##
## Makefile for makefile in /home/julian-ladjani/delivery/PSU/my_printf
##
## Made by julian ladjani
## Login   <julian.ladjani@epitech.net>
##
## Started on  Mon Nov  7 16:31:28 2016 julian ladjani
## Last update Mar Dec 20 00:47:01 2016 Julian Ladjani
##

CC 		=	gcc

SRC		=	src/main.c		\
  			src/fonc1.c		\
			src/fonc2.c		\
			src/fonc3.c		\
			src/fonc4.c		\

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

CFLAGS		=	-I./include/ -Werror

LIBDIR		=	./lib/

LIB		=	-lmy -lmy_pf -lncurses

NAME 		=	my_sokoban

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -L$(LIBDIR) $(LIB)

clean:
			$(RM) $(OBJ)
			$(RM) *~

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
