##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

#Core make
NAME_CORE	=	arcade

SRC_CORE	=	./main.cpp\
				./core/core.cpp\
				./error/error.cpp\

OBJ		=	$(SRC_CORE:.cpp=.o)

all:	core graphicals games clean

core: $(OBJ)
	g++ -o $(NAME_CORE) $(OBJ) -ldl -g3
	rm -rf $(OBJ)

graphicals:
	make -C ./lib

games:
	make -C ./games

clean clean2:
	make clean -C ./lib
	make clean -C ./games
	rm -rf $(OBJ)
	rm -rf .DS_Store

fclean: clean2
	make fclean -C ./lib
	make fclean -C ./games
	rm -rf $(NAME_CORE)
	rm -rf .DS_Store

re: fclean all

.PHONY: all clean1 clean2 fclean re core graphicals games arcade