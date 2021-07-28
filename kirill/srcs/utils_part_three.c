#include "../minishell.h"

int	ft_free(char **ptr, int res)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (res);
}
