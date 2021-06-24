#include "minishell.h"

// обработать случай, когда нет переменной HOME

char			*get_home_path(char **envp_cp)
{
	int			n;
	char        *home_path;

	n = 0;
	while (envp_cp[n] != NULL)
	{
		if (ft_strncmp(envp_cp[n], "HOME=", ft_strlen("HOME=")) == 0)
        {
            home_path = ft_substr(envp_cp[n], 5, 100);
            return (home_path);
        }
		else if (ft_strncmp(envp_cp[n], "HOME=", ft_strlen("HOME=")) != 0)

		n++;
	}
	return (NULL);
}

void			go_home(char **envp_cp)
{
	int			i;
	char		*home_path;

    char *pwd = (char *)malloc(sizeof (char) * 400);
	pwd = getwd(pwd);
	printf("%s\n", pwd);
	free(pwd);
	home_path = get_home_path(envp_cp);
//	home_path = "/home/ulistonee";
	if ((i = chdir(home_path)) == -1)
		printf("%s\n", strerror(errno));
	printf("chdir status - %d\n", i);
    char *wd = (char *)malloc(sizeof (char) * 400);
	pwd = getwd(wd);
	printf("%s\n", wd);
	free(wd);
}

char			**read_envp(t_all *all, char const *envp[])
{
	char		**envp_cp;
	int			n;

	n = 0;
	while (envp[n] != NULL)
		n++;
	if (!(envp_cp = (char **) malloc(sizeof (char*) * n)))
//		handle_error("Memory allocation error\n", all);
		printf("%s\n", strerror(errno));
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
	    if (ft_strncmp(all->cmd.argument, "~", ft_strlen("~")) == 0)
            go_home(envp_cp);
	    else
        {
            char *pwd = (char *)malloc(sizeof (char) * 400);
            pwd = getwd(pwd);
            printf("%s\n", pwd);
            free(pwd);
            int i = 0;
//          i = chdir(all->cmd.argument);
			if ((i = chdir(all->cmd.argument)) == -1)
				printf("%s\n", strerror(errno));
            printf("chdir status - %d\n", i);
            char *wd = (char *)malloc(sizeof (char) * 400);
            pwd = getwd(wd);
            printf("%s\n", wd);
            free(wd);
        }
	}
}