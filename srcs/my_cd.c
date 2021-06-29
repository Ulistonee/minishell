#include "minishell.h"

char			*get_home_path(t_all *all)
{
	int			n;
	char        *home_path;

	n = 0;
	while (all->envp_cp.envp_cp[n] != NULL)
	{
		if (ft_strncmp(all->envp_cp.envp_cp[n], "HOME=", ft_strlen("HOME=")) == 0)
        {
            home_path = ft_substr(all->envp_cp.envp_cp[n], 5, 100);
            return (home_path);
        }
//		else if (ft_strncmp(envp_cp[n], "HOME=", ft_strlen("HOME=")) != 0)
//        {
//            printf("%s\n", strerror(errno));
//        }
		n++;
	}
	return (NULL);
}

void			go_home(t_all *all)
{
	int			i;
	char		*home_path;

    char *pwd = (char *)malloc(sizeof (char) * 400);
	pwd = getwd(pwd);
	printf("%s\n", pwd);
	free(pwd);
	home_path = get_home_path(all);
	if ((i = chdir(home_path)) == -1)
		printf("bash: cd: HOME not set\n");
	printf("chdir status - %d\n", i);
    char *wd = (char *)malloc(sizeof (char) * 400);
	pwd = getwd(wd);
	printf("%s\n", wd);
	free(wd);
}

void			my_cd(int argc, t_all *all, char const *envp[])
{
	int			i;

	if (argc < 2)
	{
		go_home(all);
	}
	else if (argc == 2 && all->cmd.argument != NULL)
	{
	    if (ft_strncmp(all->cmd.argument, "~", ft_strlen("~")) == 0)
            go_home(all);
	    else
        {
            char *pwd = (char *)malloc(sizeof (char) * 400);
            pwd = getwd(pwd);
            printf("%s\n", pwd);
            free(pwd);
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