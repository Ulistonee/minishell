#include "minishell.h"

void				processor(int argc, char *argv[], char const *envp[], t_all *all)
{
//	all->cmd.name = 'E'; // echo
//	all->cmd.name = 'C'; // cd
//	all->cmd.name = 'P'; // pwd
//    all->cmd.name = 'X'; // export
    all->cmd.name = 'U'; // unset
//	all->cmd.flag = 'n';
	all->cmd.argument = ft_strdup("aa");
//	printf("%s\n", all->cmd.argument);
	if (all->cmd.name == 'E' && all->cmd.argument != NULL) {
        my_echo(all);
    }
	else if (all->cmd.name == 'C') {
        my_cd(argc, all, envp);
    }
	else if (all->cmd.name == 'P') {
        my_pwd(all);
    }
	else if (all->cmd.name == 'X') {
        my_export(all);
    }
	else if (all->cmd.name == 'U')
    {
        my_unset(all);
    }
}

int				main(int argc, char *argv[], char const *envp[])
{
	t_all		all;

//	init(&all);
    read_envp(&all, envp);
//    while(readline)
//        parser()
    processor(argc, argv, envp, &all);
}
