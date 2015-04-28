# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncharret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 19:16:41 by ncharret          #+#    #+#              #
#    Updated: 2015/04/28 20:56:02 by ncharret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = scop
SRC = scop.c loadshader.c vector.c translation_matrix.c matrix_tool.c \
	  vertex.c
OBJ = $(SRC:.c=.o) 
HEADER = libft/
CODE_DIR = libft/

.PHONY: libft.a

all: $(NAME)

libft.a:
	@$(MAKE) -C $(CODE_DIR)

$(NAME): $(OBJ)
	@$(MAKE) -C $(CODE_DIR)
	@gcc -o $(NAME) $(OBJ) -L./libft -lft -F ~/Library/Frameworks/ -framework SDL2 -framework OpenGL
	@echo "\\033[1;32m$(NAME) was created."

%.o: %.c
	@gcc -Wall -Werror -Wextra -o $@ -c $^ -I ~/Library/Frameworks/SDL2.framework/Headers 

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(CODE_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(CODE_DIR)

re: fclean all
