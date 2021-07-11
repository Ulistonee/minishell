#include "minishell.h"

void				executor(t_all *all)
{
//	all->cmd.name = 'E'; // echo
//	all->cmd.name = 'C'; // cd
//	all->cmd.name = 'P'; // pwd
//    all->cmd.name = 'X'; // export
    all->cmd.name = 'U'; // unset
//    all->cmd.name = 'N'; // env
//	all->cmd.flag = 'n';
//	all->cmd.argc = 0;
    all->cmd.argument = ft_strdup("Apple_PubSub_Socket_Render");
//	all->cmd.flag = 'n';
//	all->cmd.argument = NULL;
//	printf("%s\n", all->cmd.argument);
	if (all->cmd.name == 'E') {
        my_echo(all->cmd.flag, all->cmd.argument);
    }
	else if (all->cmd.name == 'C')
	{
        my_cd(all->cmd.argc, all->cmd.argument, all->envp_cp.envp_cp);
    }
	else if (all->cmd.name == 'P')
	{
        my_pwd();
    }
	else if (all->cmd.name == 'X')
		my_export(all->cmd.argument, all->envp_cp.envp_cp);
	else if (all->cmd.name == 'U')
		my_unset(all);
	else if (all->cmd.name == 'N') {
		my_env(all);
	}
}

int				main(int argc, char **argv, char const *envp[])
{
	t_all		all;

//	init(&all);
    read_envp(&all, envp);
//    while(readline)
//        parser()
    executor(&all);
}
