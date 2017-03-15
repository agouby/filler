# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/11 14:57:55 by agouby            #+#    #+#              #
#    Updated: 2017/03/15 11:00:37 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/agouby.filler
CC = gcc
INC = -I./includes
SRC =  $(shell find ./srcs | grep "\.c")

OBJ = $(SRC:%.c=%.o)
FLAGS = -g -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(OBJ) includes/filler.h
	make -C lib
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L./lib -lftprintf

%.o: %.c
	@gcc $(FLAGS) $(INC)  -c $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C lib

fclean: clean
	rm -f $(NAME)
	rm -rf srcs/*.c.swp
	make fclean -C lib
re: fclean all

.PHONY: all re clean fclean
