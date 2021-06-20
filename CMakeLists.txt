cmake_minimum_required(VERSION 3.19)
project(minishell C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_subdirectory(./srcs/libft)

add_executable(minishell srcs/main.c srcs/my_echo.c srcs/handle_error.c srcs/my_cd.c)
target_link_libraries(minishell termcap libft)
