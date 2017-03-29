# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/11 14:57:55 by agouby            #+#    #+#              #
#    Updated: 2017/03/29 03:08:20 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = agouby.filler
NAME_vis = visual.fx
CC = gcc
INC = -I./includes
SRC_fil =  $(shell find ./srcs | grep "\.c")
SRC_vis =  $(shell find ./visual | grep "\.c")
OBJ_fil = $(SRC_fil:%.c=%.o)
OBJ_vis = $(SRC_vis:%.c=%.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_fil) $(OBJ_vis)
	make -C libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_fil) -L./libft -lftprintf
	$(CC) $(FLAGS) -o $(NAME_vis) $(OBJ_vis) -L./libft -lftprintf -lmlx -framework Appkit -framework OpenGL

%.o: %.c
	gcc $(FLAGS) $(INC)  -c $< -o $@

clean:
	rm -rf $(OBJ_fil)
	rm -rf $(OBJ_vis)
	make clean -C libft

fclean: clean
	rm -rf $(NAME_vis)
	rm -f $(NAME)
	make fclean -C libft
re: fclean all

.PHONY: all re clean fclean
