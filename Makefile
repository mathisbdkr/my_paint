##
## EPITECH PROJECT, 2022
## hunter
## File description:
## Makefile
##

SRC	=	src/*.c	\
	src/dessin/*.c	\
	src/dessin/pen_selection/*.c	\
	src/dessin/pen_selection/pen_color/*.c	\
	src/dessin/pen_selection/pen_size/*.c	\
	src/dessin/pen_selection/pen_shape/*.c	\
	src/dessin/draw/*.c	\
	src/dessin/background_color/*.c	\
	src/bouton/*.c	\
	src/bouton/save/src/*.c	\
	src/bouton/select_save/*.c	\
	src/bouton/save/src/file_management/*.c	\
	src/bouton/save/src/bouton/*.c	\
	src/bouton/help/src/*.c	\
	src/bouton/save/src/search_bare/*.c	\
	src/sprite/*.c	\
	lib/*.c

OBJ	=	$(SRC/.c=.o)

NAME	=	my_paint

LIB	=	-lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-window

$(NAME):
	gcc $(SRC) $(LIB) -lm -o $(NAME)

all:	$(NAME) clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re:	fclean all

.PHONY:	$(NAME) all clean
