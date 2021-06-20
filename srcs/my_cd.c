#include "minishell.h"

// обработаь случай, когда нет переменной HOME
//

char			*get_home_path(char **envp_cp)
{
	int			n;


	n = 0;
	while (envp_cp != NULL)
	{
		if (ft_strncmp(envp_cp[n], "HOME=", ft_strlen("HOME=")) == 0)
			return (envp_cp[n]);
	}
	return (NULL);

}

void			go_home(char **envp_cp)
{
	int			i;
	char		*home_path;

	char *pwd = getwd(NULL);
	printf("%s\n", pwd);
	free(pwd);
	home_path = get_home_path(envp_cp);
	i = chdir(home_path);
	printf("chdir status - %d\n", i);
	pwd = getwd(NULL);
	printf("%s\n", pwd);
	free(pwd);
}

char			**read_envp(t_all *all, char const *envp[])
{
	char		**envp_cp;
	int			n;

	n = 0;
	while (envp[n] != NULL)
		n++;
	if (!(envp_cp = (char **) malloc(sizeof (char*) * n)))
		handle_error("Memory allocation error\n", all);
	n = 0;
	while (envp[n] != NULL)
	{
		envp_cp[n] = ft_strdup(envp[n]);
		n++;
	}
	return (envp_cp);
}

void			my_cd(int argc, t_all *all, char const *envp[])
{
	char		**envp_cp;
	int			i;

	envp_cp = read_envp(all, envp);
	if (argc < 2)
	{
		go_home(envp_cp);
	}
	else if (argc == 2)
	{
		char *pwd = getwd(NULL);
		printf("%s\n", pwd);
		free(pwd);
		int i = 0;
		i = chdir(all->cmd.argument);
		printf("chdir status - %d\n", i);
		pwd = getwd(NULL);
		printf("%s\n", pwd);
		free(pwd);
	}
}