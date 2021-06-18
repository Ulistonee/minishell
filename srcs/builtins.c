#include "minishell.h"

static void		read_envp(t_all *all, char const *envp[])
{
	char		**envp_cp;
	int			length;
	int			i;

	i = 0;
	length = 0;
//	length = ft_strlen(*envp);
	envp_cp = (char**)malloc(sizeof(char) * length);
	envp_cp[length] = 0;
	while (*envp != NULL)
	{
		length++;

//		envp_cp[i] = ft_strdup(envp[i]);
//		i++;
		(*envp)++;
	}
	printf("%d\n", length);
}

void			my_cd(t_all *all, char const *envp[])
{
//	read_envp(all, envp);
}

void			my_echo(t_all *all)
{
//	printf("working\n");
	printf("%s", all->cmd.argument);
}