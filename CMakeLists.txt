cmake_minimum_required(VERSION 3.16)
project(minishell C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_subdirectory(kirill/libft)

add_executable(minishell
        kirill/main.c
        kirill/parser.c
        kirill/ft_list.c
        kirill/utils.c
        kirill/add_redirect.c
        kirill/srcs/executor.c
        kirill/srcs/my_echo.c
        kirill/srcs/my_cd.c
        kirill/srcs/my_pwd.c
        kirill/srcs/my_export.c
        kirill/srcs/my_fork.c
        kirill/srcs/utils.c
        kirill/srcs/my_unset.c
        kirill/srcs/another_exit.c
        kirill/srcs/my_env.c)
target_link_libraries(minishell termcap libft readline)
