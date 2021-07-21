cmake_minimum_required(VERSION 3.16)
project(minishell C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_subdirectory(./srcs/libft)

add_executable(minishell
        srcs/*.c
        srcs/another_exit.c
        )
target_link_libraries(minishell termcap libft)
