cmake_minimum_required(VERSION 3.16)
project(minishell C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_subdirectory(./srcs/libft)

add_executable(minishell
		srcs/main.c
        srcs/my_echo.c
        srcs/my_cd.c
        srcs/my_pwd.c
        srcs/my_export.c
        srcs/my_fork.c
        srcs/utils.c
        srcs/my_unset.c
        srcs/my_env.c)
target_link_libraries(minishell termcap libft)
