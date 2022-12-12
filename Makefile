# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 14:08:45 by msaouab           #+#    #+#              #
#    Updated: 2022/12/08 15:50:31 by msaouab          ###   ########.fr        #
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

SRC =	main.cpp\

I_VECTOR = ./vector/vector.hpp
I_STACK = ./stack/stack.hpp
I_MAP =	./map/map.hpp
I_RBT =	./RB_TREE/Redblack_tree.hpp
I_SET =	./set/set.hpp

HEADERS = $(I_VECTOR) $(I_STACK) $(I_MAP) $(I_RBT) $(I_SET)

OBJ = $(SRC:.cpp=.o)

CC = c++ -std=c++98

CFLAGS = -Wall -Wextra -Werror

all : credit $(NAME) vector stack map rb_tree set

vector: credit $(NAME_V)

stack: credit $(NAME_S)

map: credit $(NAME_M)

rb_tree: credit $(NAME_R)

set: credit $(NAME_Se)

credit:
	@echo "	 ╔█████████████████████████████████████████████████████████████████████████████╗"
	@echo "	██                                                                             ██"
	@echo "	██  ██████╗ ██████╗ ███╗   ██╗████████╗ ╔██╗    ██╗███╗   ██╗███████╗███████╗  ██"
	@echo "	██ ██╔════╝██╔═══██╗████╗  ██║╚══██╔══╝╔████╗   ██║████╗  ██║██╔════╝██╔═══██╗ ██"
	@echo "	██ ██║     ██║   ██║██╔██╗ ██║   ██║  ╔██╝╚██╗  ██║██╔██╗ ██║█████╗  ███████╔╝ ██"
	@echo "	██ ██║     ██║   ██║██║╚██╗██║   ██║ ╔████████╗ ██║██║╚██╗██║██╔══╝  ██╔══██╗  ██"
	@echo "	██ ╚██████╗╚██████╔╝██║ ╚████║   ██║╔██══════██╗██║██║ ╚████║███████╗██║  ╚██╗ ██"
	@echo "	██  ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝╚═╝      ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝╚═╝   ╚═╝ ██"
	@echo "	██                                 ┃By:$(GREEN) msaouab$(ED)┃			       ██"
	@echo "	 ╚█████████████████████████████████████████████████████████████████████████████╝"

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "	$(bold)$(magenta)Combilation Done.$(ED)"

$(NAME_V): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME_V)
		@echo "	$(bold)$(magenta)Combilation Vector Done.$(ED)"

$(NAME_S): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME_S)
		@echo "	$(bold)$(magenta)Combilation Stack Done.$(ED)"

$(NAME_M): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME_M)
		@echo "	$(bold)$(magenta)Combilation Map Done.$(ED)"

$(NAME_R): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME_R)
		@echo "	$(bold)$(magenta)Combilation RED black tree Done.$(ED)"

$(NAME_Se): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME_Se)
		@echo "	$(bold)$(magenta)Combilation Set Done.$(ED)"

clean: 
		@rm -f $(OBJ)
		@echo "clean Done."

fclean: clean
		@rm -f $(NAME) $(NAME_V) $(NAME_S) $(NAME_M) $(NAME_R) $(NAME_Se)
		@echo "fclean Done."

re: fclean all
