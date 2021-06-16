NAME		= minishell

SRCS	= \
			srcs/main.c

OBJS		= $(patsubst %.c, %.o, $(SRCS))

CC			= gcc
FLAGS		= -Wall -Wextra -Werror
HEADER		= srcs/minishell.h

RM			= rm -f

all:		init ${NAME}

init:
			make -C srcs/libft

$(NAME):	$(OBJS) $(HEADER)
#MAC:
			$(CC) $(FLAGS) $(OBJS) -ltermcap -o $(NAME)

#Lnx:
			#$(CC) $(FLAGS) $? $(HEADER) -Llibft -lft -Llibmlx -lmlx -lXext -lX11 -lbsd -lm -o $(NAME)

%.o : %.c
			${CC} $(FLAGS) -c $< -o $@

#LINUX:
	# $(CC) $(FLAGS) main.c -Llibft -lft

clean:
			${RM} ${OBJS}
			make -C srcs/libft clean

fclean:		clean
			$(RM) -rf $(NAME)
			make -C srcs/libft fclean

re:			fclean all

norm:
			norminettev2 $(SRCS)
			norminettev2 $(HEADER)
			norminettev2 srcs/libft/*.c
			norminettev2 srcs/libft/*.h

.PHONY:		all clean fclean re
