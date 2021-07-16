# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchalmer <marwin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 17:31:41 by rchalmer          #+#    #+#              #
#    Updated: 2021/01/21 15:12:24 by rchalmer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isascii.c ft_memcmp.c ft_strrchr.c ft_atoi.c ft_isdigit.c ft_memcpy.c ft_strlcpy.c ft_tolower.c ft_bzero.c ft_isprint.c ft_memmove.c ft_toupper.c ft_isalnum.c ft_memccpy.c ft_memset.c ft_strncmp.c ft_isalpha.c ft_memchr.c ft_strchr.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_putnbr_fd.c ft_strlen.c ft_putchar_fd.c ft_strlcat.c ft_putstr_fd.c ft_putendl_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_itoa.c ft_free_mem.c ft_itoa_base.c ft_itoa_uhex.c ft_itoa_u.c

BONUS =  ft_lstnew.c

OBJECTS = $(SRCS:.c=.o)
OBJECTS_B = $(BONUS:.c=.o) 

FLAGS = -Wall -Wextra -Werror -c

INCLUDES = ./

all: $(NAME)

.c.o.:
	gcc $(FLAGS) -I$(INCLUDES) $< -o $(<:.c=.o)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(OBJECTS_B)
	ar rcs $(NAME) $(OBJECTS_B)
	

clean:
	/bin/rm -f $(OBJECTS) $(OBJECTS_B)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:     all clean fclean re
