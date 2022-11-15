# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 14:08:45 by msaouab           #+#    #+#              #
#    Updated: 2022/11/14 13:19:37 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Containers

SRC =	main.cpp\
		./containers/map.cpp\
		./containers/stack.cpp\
		./containers/vector.cpp

INCLUDE =	./containers/vector.hpp\
			./containers/map.hpp\
			./containers/stack.hpp

OBJ = $(SRC:.cpp=.o)

CC = c++ -std=c++98

CFLAGS = -Wall -Wextra -Werror

bold = $(shell tput bold)

magenta = `tput setaf 5`

ED = \033[0m

all : $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "$(bold)$(magenta)Combilation Done.$(ED)"

clean: 
		@rm -f $(OBJ)
		@echo "clean Done."

fclean: clean
		@rm -f $(NAME)
		@echo "fclean Done."

re: fclean all