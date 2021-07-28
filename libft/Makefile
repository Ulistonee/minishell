# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 20:44:29 by kirill            #+#    #+#              #
#    Updated: 2021/07/28 20:18:48 by cvirgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strlen.c \
	  ft_strchr.c\
	  ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	 ft_strdup.c ft_calloc.c ft_bzero.c\
	ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = ft_strlen.o \
      ft_strchr.o\
	  ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o\
     ft_strdup.o ft_calloc.o ft_bzero.o\
	ft_substr.o ft_strjoin.o ft_split.o ft_itoa.o \
	ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o 

INCLUDE = libft.h

AR = ar rc

all: $(NAME) $(OBJ)

$(NAME): $(OBJ) $(INCLUDE)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(NAME) ${OBJ_B} ${OBJ} ${INCLUDE}
	$(AR) $(NAME) $(OBJ_B) $(OBJ)
	ranlib $(NAME)

%.o: %.c 
	gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	rm -f ${OBJ} ${OBJ_B}

fclean:	clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
