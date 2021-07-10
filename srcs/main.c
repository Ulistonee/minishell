#include "minishell.h"

void				processor(int argc, char *argv[], char const *envp[], t_all *all) {
//	all->cmd.name = 'E'; // echo
//	all->cmd.name = 'C'; // cd
//	all->cmd.name = 'P'; // pwd
//    all->cmd.name = 'X'; // export
	all->cmd.name = 'N'; // env
//	all->cmd.flag = 'n';
	all->cmd.argument = ((char*)malloc(sizeof(char) * 25));
//	all->cmd.argument = NULL;
//	all->cmd.argument = "/Users/rchalmer";
//	printf("%s\n", all->cmd.argument);
    read_envp(all, envp);
	if (all->cmd.name == 'E' && all->cmd.argument != NULL)
		my_echo(all);
	else if (all->cmd.name == 'C')
		my_cd(argc, all, envp);
	else if (all->cmd.name == 'P')
        my_pwd(all);
	else if (all->cmd.name == 'X')
	    my_export(all);
	else if (all->cmd.name == 'N')
	{
		my_env(all);
	}
}

int				main(int argc, char *argv[], char const *envp[])
{
	t_all		all;

	processor(argc, argv, envp, &all);
}
