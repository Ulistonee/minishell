# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 17:21:49 by cvirgin           #+#    #+#              #
#    Updated: 2021/07/28 20:06:12 by cvirgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c parser.c ft_list.c utils.c add_redirect.c dollar_aizhan.c redirect4.c ft_list2.c\
			utils2.c\
			utils3.c\
			utils4.c\
			parser3.c\
			parser4.c\
			parser5.c\
			count_argv.c\
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
			srcs/utils_export.c \
			srcs/utils_part_two.c \
			srcs/utils_part_three.c \
			srcs/executor_utils.c \
			srcs/executor_utils_two.c \

OBJ = $(patsubst %.c, %.o, $(SRC))

INCLUDE = minishell.h

FLAGS = -Wall -Wextra -Werror

OS			:= $(shell uname)

all: $(NAME)

$(NAME): $(INCLUDE) $(SRC)
	make bonus -C libft
	#gcc $(FLAGS) $(SRC) -g -Llibft -lft -lreadline -L/Users/cvirgin/.brew/opt/readline/lib -I/Users/cvirgin/.brew/opt/readline/include -o $(NAME)
	gcc $(FLAGS) $(SRC) -g -Llibft -lft -lreadline -L/Users/rchalmer/.brew/opt/readline/lib -I/Users/rchalmer/.brew/opt/readline/include -o $(NAME)
	#gcc $(SRC) -g -Llibft -lft -lreadline -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include -o $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean:	clean
	make fclean -C libft
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re