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

NAME = minishell

SRC = main.c parser.c ft_list.c utils.c add_redirect.c dollar_aizhan.c\
			srcs/executor.c \
			srcs/my_echo.c \
			srcs/my_cd.c \
			srcs/my_pwd.c \
			srcs/my_export.c \
			srcs/my_unset.c \
			srcs/utils.c \
			srcs/my_env.c \
			srcs/my_heredoc.c \
			srcs/my_exit.c \
			srcs/utils_export.c

OBJ = $(patsubst %.c, %.o, $(SRC))

INCLUDE = minishell.h

FLAGS = -Wall -Wextra -Werror

OS			:= $(shell uname)

all: $(NAME)

$(NAME): $(INCLUDE) $(SRC)
	make bonus -C libft
	#gcc $(SRC) -g -Llibft -lft -lreadline -L/Users/cvirgin/.brew/opt/readline/lib -I/Users/cvirgin/.brew/opt/readline/include -o $(NAME)
	gcc $(SRC) -g -Llibft -lft -lreadline -L/Users/rchalmer/.brew/opt/readline/lib -I/Users/rchalmer/.brew/opt/readline/include -o $(NAME)
	#gcc $(SRC) -g -Llibft -lft -lreadline -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include -o $(NAME)


clean:
	make clean -C libft
	rm -f $(OBJ)

fclean:	clean
	make fclean -C libft
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re