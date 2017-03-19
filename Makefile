# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/11 14:57:55 by agouby            #+#    #+#              #
#    Updated: 2017/03/16 13:43:12 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/agouby.filler
CC = gcc
INC = -I./includes
SRC =  $(shell find ./srcs | grep "\.c" | grep -v "\.c.swp")

OBJ = $(SRC:%.c=%.o)
FLAGS = -g -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(OBJ) includes/filler.h
	rm -rf srcs/*.c.swp
	make -C lib
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L./lib -lftprintf

%.o: %.c
	@gcc $(FLAGS) $(INC)  -c $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C lib

fclean: clean
	rm -rf srcs/*.c.swp
	rm -f $(NAME)
	make fclean -C lib
re: fclean all

.PHONY: all re clean fclean
