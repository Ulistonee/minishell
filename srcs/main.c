#include "minishell.h"

void				processor(int argc, char *argv[], char const *envp[], t_all *all)
{
//	all->cmd.name = 'E'; // echo
//	all->cmd.name = 'C'; // cd
//	all->cmd.name = 'P'; // pwd
//    all->cmd.name = 'X'; // export
<<<<<<< HEAD
    all->cmd.name = 'U'; // unset
//	all->cmd.flag = 'n';
	all->cmd.argument = ft_strdup("aa");
=======
	all->cmd.name = 'N'; // env
//	all->cmd.flag = 'n';
	all->cmd.argument = ((char*)malloc(sizeof(char) * 25));
//	all->cmd.argument = NULL;
//	all->cmd.argument = "/Users/rchalmer";
>>>>>>> 0a8ac813bd0805cce57a445b76b4554d97a9c706
//	printf("%s\n", all->cmd.argument);
	if (all->cmd.name == 'E' && all->cmd.argument != NULL) {
        my_echo(all);
    }
	else if (all->cmd.name == 'C') {
        my_cd(argc, all, envp);
    }
	else if (all->cmd.name == 'P') {
        my_pwd(all);
<<<<<<< HEAD
    }
	else if (all->cmd.name == 'X') {
        my_export(all);
    }
	else if (all->cmd.name == 'U')
    {
        my_unset(all);
    }
=======
	else if (all->cmd.name == 'X')
	    my_export(all);
	else if (all->cmd.name == 'N')
	{
		my_env(all);
	}
>>>>>>> 0a8ac813bd0805cce57a445b76b4554d97a9c706
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
