#include "../minishell.h"

int	my_pwd(void)
{
	char		*pwd;

	pwd = (char *)malloc(sizeof (char) * 500);
	pwd = getcwd(pwd, 500);
	printf("%s\n", pwd);
	free(pwd);
	return (EXIT_SUCCESS);
}
