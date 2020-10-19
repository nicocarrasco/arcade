##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAME_NIBBLER	=	lib_arcade_nibbler.so
NAME_PACMAN	=	lib_arcade_pacman.so

SRC_NIBBLER	=	nibbler/nibbler.cpp\
				nibbler/entrypoint.cpp\

SRCO_NIBBLER	=	nibbler.o\
					entrypoint.o

SRC_PACMAN	=	pacman/pacman.cpp\
				pacman/entrypoint.cpp\

SRCO_PACMAN	=	pacman.o\
				entrypoint.o\

CFLAGS	=	-g3 -W -Wall -Wextra


all:	 games clean

games:
	export LD_LIBRARY_PATH=.
	g++ -c -fpic $(SRC_NIBBLER)
	g++ -shared -o $(NAME_NIBBLER) $(SRCO_NIBBLER)
	g++ -c -fpic $(SRC_PACMAN) $(CFLAGS)
	g++ -shared -o $(NAME_PACMAN) $(SRCO_PACMAN)

clean clean2:
	rm -f *.o
	rm -f *~
	rm -f \#*\#
	rm -f vgcore.*
	rm -rf .DS_Store

fclean: clean2
	rm -f $(NAME_NIBBLER)
	rm -f $(NAME_PACMAN)
	rm -rf .DS_Store

re: fclean all

.PHONY: all clean1 clean2 fclean re games