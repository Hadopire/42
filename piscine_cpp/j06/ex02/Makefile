# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncharret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 19:16:41 by ncharret          #+#    #+#              #
#    Updated: 2015/06/15 14:44:32 by ncharret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = identify
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@clang++ -o $(NAME) $(OBJ)
	@echo "\\033[1;32m$(NAME) was created."

%.o: %.cpp
	@clang++ -Wall -Werror -Wextra -o $@ -c $^

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
