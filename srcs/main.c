#include "minishell.h"

int				check(int argc, char *argv[], char const *envp[], t_all *all) {
	int n = 0;

	while (envp[n] != NULL) {
		printf("envp[%d]: <%s\n", n, envp[n]);
		n++;
	}
//	all->cmd.name = 'E';
	all->cmd.name = 'C';
	all->cmd.argument = ((char*)malloc(sizeof(char) * 18));
//	all->cmd.argument = "minishell";
	all->cmd.argument = "/Users/rchalmer/c";
//	printf("%s\n", all->cmd.argument);
	if (all->cmd.name == 'E' && all->cmd.argument != NULL)
		my_echo(all);
	else if (all->cmd.name == 'C')
		my_cd(all, envp);
	return 0;
}

int				main(int argc, char *argv[], char const *envp[])
{
	t_all		all;

//	all.cmd.name = 'C';
	check(argc, argv, envp, &all);
}
