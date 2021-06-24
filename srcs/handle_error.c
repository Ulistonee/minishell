#include "minishell.h"

void			handle_error(char *message, t_all *all)
{
	ft_putstr_fd("Error\n", 0);
	ft_putstr_fd(message, 0);
//	auto_clear(all);
//	exit(EXIT_FAILURE);
}