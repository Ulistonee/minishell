#include "minishell.h"

void			my_echo(t_all *all)
{
	printf("%s", all->cmd.argument);
}