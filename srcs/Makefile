NAME		= minishell

SRCS	= \
			main.c \
			my_echo.c \
			my_cd.c \
			handle_error.c

OBJS		= $(patsubst %.c, %.o, $(SRCS))

CC			= gcc
FLAGS		= #-Wall -Wextra -Werror
HEADER		= minishell.h

RM			= rm -f

all:		init ${NAME} ${HEADER}

init:
			make -C libft

$(NAME):	$(OBJS) $(HEADER)

#MAC:
			 $(CC) $(FLAGS) ${OBJS} -ltermcap -Llibft -lft -o $(NAME)

#Lnx:
			#$(CC) $(FLAGS) $? $(HEADER) -ltermcap -o $(NAME)

%.o : %.c
			${CC} $(FLAGS) -c $< -o $@

#LINUX:
	# $(CC) $(FLAGS) main.c -Llibft -lft

clean:
			${RM} ${OBJS} *.out
			make -C libft clean

fclean:		clean
			$(RM) -rf $(NAME)
			make -C libft fclean

re:			fclean all

norm:
			norminettev2 $(SRCS)
			norminettev2 $(HEADER)
			norminettev2 libft/*.c
			norminettev2 libft/*.h

.PHONY:		all clean fclean re
