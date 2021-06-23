#include "minishell.h"

void				processor(int argc, char *argv[], char const *envp[], t_all *all) {
	all->cmd.name = 'E';
//	all->cmd.name = 'C';
	all->cmd.argument = ((char*)malloc(sizeof(char) * 25));
	all->cmd.argument = "abcd";
//	all->cmd.argument = "~";
//	printf("%s\n", all->cmd.argument);
	if (all->cmd.name == 'E' && all->cmd.argument != NULL)
		my_echo(all);
	else if (all->cmd.name == 'C')
		my_cd(argc, all, envp);
}

int				main(int argc, char *argv[], char const *envp[])
{
	t_all		all;

	processor(argc, argv, envp, &all);
}
