#include "../minishell.h"

int			my_echo(char flag, char *argument)
{
	if (flag == 'n')
		printf("%s", argument);
	else if (argument == NULL)
		printf("");
	else
		printf("%s\n", argument);
    return (1);
}