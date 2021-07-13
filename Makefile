# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 17:21:49 by cvirgin           #+#    #+#              #
#    Updated: 2021/04/13 22:39:46 by cvirgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = my_bash

SRC = main.c parser.c ft_list.c utils.c add_redirect.c

OBJ = main.o parser.o ft_list.o utils.o add_redirect.o

INCLUDE = minishell.h

FLAGS = -Wall -Wextra -Werror

OS			:= $(shell uname)

all: $(NAME)

$(NAME): $(INCLUDE) $(SRC)
	make bonus -C libft
	gcc $(SRC) -g -Llibft -lft -lreadline -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include -o $(NAME) 


clean:
	make clean -C libft
	rm -f $(OBJ)

fclean:	clean
	make fclean -C libft
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re