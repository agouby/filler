# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/11 14:57:55 by agouby            #+#    #+#              #
#    Updated: 2017/03/24 17:01:59 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/agouby.filler
CC = gcc
INC = -I./includes
SRC_fil =  $(shell find ./srcs | grep "\.c" | grep -v "\.c.swp")
SRC_vis =  $(shell find ./visual | grep "\.c" | grep -v "\.c.swp")

OBJ_fil = $(SRC_fil:%.c=%.o)
OBJ_vis = $(SRC_vis:%.c=%.o)
FLAGS = -g -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(OBJ_fil) $(OBJ_vis) includes/filler.h includes/visual.h
	rm -rf srcs/*.c.swp
#	rm -rf visual.txt
#	touch visual.txt
	make -C lib
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_fil) -L./lib -lftprintf
	$(CC) $(FLAGS) -o visual.fx $(OBJ_vis) -L./lib -lftprintf -lmlx -framework Appkit -framework OpenGL

%.o: %.c
	gcc $(FLAGS) $(INC)  -c $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C lib

fclean: clean
	rm -rf visual.cfg
	rm -rf srcs/*.c.swp
	rm -rf visual/*.o
	rm -rf visual.fx
	rm -rf srcs/*.o
	rm -f $(NAME)
	make fclean -C lib
re: fclean all

.PHONY: all re clean fclean
