cmake_minimum_required(VERSION 3.16)
project(minishell C)

set(CMAKE_C_STANDARD 99)

#add_library(readline)

#include_directories(/Users/cvirgin/.brew/opt/readline/lib/)
include_directories(/Users/rchalmer/.brew/opt/readline/lib/)

#link_directories(/Users/cvirgin/.brew/opt/readline/lib/)
link_directories(/Users/rchalmer/.brew/opt/readline/lib/)

#find_library(NAMES libreadline PATHS /Users/cvirgin/.brew/opt/readline/lib/ /Users/cvirgin/.brew/opt/readline/lib/)
find_library(NAMES libreadline PATHS /Users/rchalmer/.brew/opt/readline/lib/ /Users/rchalmer/.brew/opt/readline/lib/)
#set(INCLUDE_DIR /Users/cvirgin/.brew/opt/readline/lib/)
set(INCLUDE_DIR /Users/rchalmer/.brew/opt/readline/lib/)

add_subdirectory(libft)

add_executable(minishell
		add_redirect.c
#		clear_arr.c
		ft_list.c
		main.c
		parser.c
		utils.c
		dollar_aizhan.c
		srcs/my_env.c
		srcs/my_exit.c
		srcs/executor.c
		srcs/my_cd.c
		srcs/my_echo.c
		srcs/my_export.c
		srcs/my_pwd.c
		srcs/my_unset.c
		srcs/utils.c
		srcs/my_heredoc.c
		srcs/utils_export.c
        )
target_link_libraries(minishell readline termcap libft)
