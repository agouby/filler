# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/07 23:40:39 by agouby            #+#    #+#              #
#    Updated: 2017/03/29 01:54:30 by agouby           ###   ########.fr        #
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
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

%.o: %.c	
		@echo $<
			@gcc $(FLA) $(INC)  -c $< -o $@
clean:
		@/bin/rm -f $(OBJ)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
