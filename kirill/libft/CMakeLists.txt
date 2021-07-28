cmake_minimum_required(VERSION 3.16)

project(libft C)

set(CMAKE_C_STANDARD 11)

add_library(libft STATIC
		ft_strlen.c
ft_strchr.c
ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c
ft_strdup.c ft_calloc.c ft_bzero.c
ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
        libft.h)
