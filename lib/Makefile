##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAME_NCURSES	=	lib_arcade_ncurses.so
NAME_SFML	=	lib_arcade_sfml.so
NAME_SDL	=	lib_arcade_sdl.so

# NCURSES LIB
SRC_NCURSES	=	ncurses/ncurses.cpp\
				ncurses/entrypoint.cpp\

SRCO_NCURSES	=	ncurses.o\
					entrypoint.o\

# SFML LIB
SRC_SFML	=	sfml/sfml.cpp\
				sfml/entrypoint.cpp\

SRCO_SFML	=	sfml.o\
				entrypoint.o\

# SDL LIB
SRC_SDL	=	sdl/sdl.cpp\
			sdl/entrypoint.cpp\

SRCO_SDL	=	sdl.o\
				entrypoint.o\

CFLAGS	=	-g3 -W -Wall -Wextra

all:	 graphicals clean

graphicals:
	export LD_LIBRARY_PATH=.
	g++ -c -fpic $(SRC_NCURSES) -g3
	g++ -shared -lncurses  -o $(NAME_NCURSES) $(SRCO_NCURSES) -g3
	g++ -c -fpic $(SRC_SFML) $(CFLAGS)
	g++ -shared -o $(NAME_SFML) $(SRCO_SFML) -lsfml-graphics -lsfml-window -lsfml-system
	g++ -c -fpic $(SRC_SDL)
	g++ -shared -lSDL2 -lSDL2_ttf -o $(NAME_SDL) $(SRCO_SDL)

clean clean2:
	rm -f *.o
	rm -f *~
	rm -f \#*\#
	rm -f vgcore.*
	rm -rf .DS_Store


fclean: clean2
	rm -f $(NAME_NCURSES)
	rm -f $(NAME_SFML)
	rm -f $(NAME_SDL)
	rm -rf .DS_Store

re: fclean all

.PHONY: all clean1 clean2 fclean re graphicals