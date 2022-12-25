# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 14:08:45 by msaouab           #+#    #+#              #
#    Updated: 2022/12/25 15:45:32 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

bold = $(shell tput bold)
magenta = `tput setaf 5`
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
ED = \033[0m
LINE_CLEAR = \x1b[1A\x1b[M

NAME = my_Containers
NAME_V = my_Vector
NAME_S = my_Stack
NAME_R = my_Rb_Tree
NAME_M = my_Map
NAME_Se = my_Set
NAME_I = my_It

SRC =	Testers/main.cpp
SRC_Map =	Testers/mapTester.cpp
SRC_Stack =	Testers/stacktest.cpp
SRC_Set =	Testers/setTester.cpp
SRC_RBT =	Testers/testrbt.cpp
SRC_Vector =	Testers/vectortest.cpp
SRC_It =	Testers/xtraTest.cpp

I_VECTOR = ./vector/vector.hpp
I_STACK = ./stack/stack.hpp
I_MAP =	./map/map.hpp
I_RBT =	./RB_TREE/Redblack_tree.hpp
I_SET =	./set/set.hpp
I_it = ./iterators/iterator.hpp

HEADERS = $(I_VECTOR) $(I_STACK) $(I_MAP) $(I_RBT) $(I_SET)

OBJ = $(SRC:.cpp=.o)
OBJ_Map = $(SRC_Map:.cpp=.o)
OBJ_RBT = $(SRC_RBT:.cpp=.o)
OBJ_Set = $(SRC_Set:.cpp=.o)
OBJ_It = $(SRC_It:.cpp=.o)
OBJ_Stack = $(SRC_Stack:.cpp=.o)
OBJ_Vector = $(SRC_Vector:.cpp=.o)

CC = c++ -std=c++98

CFLAGS = -Wall -Wextra -Werror

all : credit $(NAME) vector stack map rb_tree set

vector: credit $(NAME_V)

stack: credit $(NAME_S)

map: credit $(NAME_M)

rb_tree: credit $(NAME_R)

set: credit $(NAME_Se)

it: credit $(NAME_I)

credit:
	@echo "\n	╔█████████████████████████████████████████████████████████████████████████████╗"
	@echo "	██                                                                             ██"
	@echo "	██  ██████╗ ██████╗ ███╗   ██╗████████╗ ╔██╗    ██╗███╗   ██╗███████╗███████╗  ██"
	@echo "	██ ██╔════╝██╔═══██╗████╗  ██║╚══██╔══╝╔████╗   ██║████╗  ██║██╔════╝██╔═══██╗ ██"
	@echo "	██ ██║     ██║   ██║██╔██╗ ██║   ██║  ╔██╝╚██╗  ██║██╔██╗ ██║█████╗  ███████╔╝ ██"
	@echo "	██ ██║     ██║   ██║██║╚██╗██║   ██║ ╔████████╗ ██║██║╚██╗██║██╔══╝  ██╔══██╗  ██"
	@echo "	██ ╚██████╗╚██████╔╝██║ ╚████║   ██║╔██══════██╗██║██║ ╚████║███████╗██║  ╚██╗ ██"
	@echo "	██  ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝╚═╝      ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝╚═╝   ╚═╝ ██"
	@echo "	██                                 ┃By:$(GREEN) msaouab$(ED)┃			       ██"
	@echo "	 ╚█████████████████████████████████████████████████████████████████████████████╝\n\n"

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo " $(bold)$(magenta)Combilation Done.$(ED) $(LINE_CLEAR)"
		@sleep 1
		@rm $(OBJ)

$(NAME_V): $(OBJ_Vector)
		@$(CC) $(CFLAGS) $(OBJ_Vector) -o $(NAME_V)
		@echo " $(bold)$(magenta)Combilation Vector Done.$(ED) $(LINE_CLEAR)"
		@sleep 1
		@rm -f $(OBJ_Vector)

$(NAME_S): $(OBJ_Stack)
		@$(CC) $(CFLAGS) $(OBJ_Stack) -o $(NAME_S)
		@echo " $(bold)$(magenta)Combilation Stack Done.$(ED) $(LINE_CLEAR)"
		@sleep 1
		@rm -f $(OBJ_Stack)

$(NAME_M): $(OBJ_Map)
		@$(CC) $(CFLAGS) $(OBJ_Map) -o $(NAME_M)
		@echo " $(bold)$(magenta)Combilation Map Done.$(ED) $(LINE_CLEAR)"
		@sleep 1
		@rm -f $(OBJ_Map)

$(NAME_R): $(OBJ_RBT)
		@$(CC) $(CFLAGS) $(OBJ_RBT) -o $(NAME_R)
		@echo " $(bold)$(magenta)Combilation RED black tree Done.$(ED) $(LINE_CLEAR)"
		@sleep 1
		@rm -f $(OBJ_RBT)

$(NAME_Se): $(OBJ_Set)
		@$(CC) $(CFLAGS) $(OBJ_Set) -o $(NAME_Se)
		@echo " $(bold)$(magenta)Combilation Set Done.$(ED) $(LINE_CLEAR)"
		@sleep 1
		@rm -f $(OBJ_Set)

$(NAME_I): $(OBJ_It)
		@$(CC) $(CFLAGS) $(OBJ_It) -o $(NAME_Se)
		@echo " $(bold)$(magenta)Combilation Set Done.$(ED) $(LINE_CLEAR)"
		@sleep 1
		@rm -f $(OBJ_It)

clean: 
		@rm -f $(OBJ) $(OBJ_It) $(OBJ_Map) $(OBJ_RBT) $(OBJ_Vector) $(OBJ_Set) $(OBJ_Stack)
		@echo " $(bold)$(magenta)clean Done.$(ED) $(LINE_CLEAR)"

fclean: clean
		@rm -f $(NAME) $(NAME_V) $(NAME_S) $(NAME_M) $(NAME_R) $(NAME_Se)
		@echo " $(bold)$(magenta)fclean Done.$(ED) $(LINE_CLEAR)"

re: fclean all
