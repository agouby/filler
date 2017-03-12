# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/07 23:40:39 by agouby            #+#    #+#              #
#    Updated: 2017/03/12 04:05:57 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC_PATH = ../includes/

SRC = $(shell find . | grep "\.c")
INC += $(addprefix -iquote, $(INC_PATH))

OBJ = ${SRC:.c=.o}
	FLA = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
		@ar rcus $(NAME) $(OBJ)
			@echo "created $(NAME)"

%.o: %.c	
		@echo "$<"
			@gcc $(FLA) $(INC)  -c $< -o $@

clean:
		@/bin/rm -f $(OBJ)
			@echo "cleaned '*.o'"

fclean: clean
		@/bin/rm -f $(NAME)
			@echo "cleaned $(NAME)" 

re: fclean all

.PHONY: all clean fclean re

