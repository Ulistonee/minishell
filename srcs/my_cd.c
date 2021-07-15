#include "minishell.h"

//нужно фришить abs_path
char            *get_absolute_path(char **envp_cp, char *relative_path)
{
    char        *home;
    char        *abs_path;

    abs_path = NULL;
    home = get_value(envp_cp, "HOME");
    abs_path = ft_strjoin(home, relative_path + 1);
    return (abs_path);
}

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
//		else if (ft_strncmp(envp_cp[n], "HOME=", ft_strlen("HOME=")) != 0)
//        {
//            printf("%s\n", strerror(errno));
//        }
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
	if ((i = chdir(home_path)) == -1)
		printf("bash: cd: HOME not set\n");
	printf("chdir status - %d\n", i);
    char *wd = (char *)malloc(sizeof (char) * 400);
	pwd = getwd(wd);
	printf("%s\n", wd);
	free(wd);
}

int			my_cd(int argc, char *argument, char **envp_cp)
{
	int			i;
	char        *abs_path;

	if (argc < 2)
	{
		go_home(envp_cp);
	}
	else if (argc == 2 && argument != NULL)
	{
	    if (ft_strncmp(argument, "~", ft_strlen("~") + 1) == 0)
            go_home(envp_cp);
	    else
        {
            char *pwd = (char *)malloc(sizeof (char) * 400);
            pwd = getwd(pwd);
            printf("%s\n", pwd);
            free(pwd);
            if (*argument == '~')
            {
                abs_path = get_absolute_path(envp_cp, argument);
                if ((i = chdir(abs_path)) == -1)
                    printf("%s\n", strerror(errno));
                if (abs_path)
                    free(abs_path);
            }
            else if ((i = chdir(argument)) == -1)
				printf("%s\n", strerror(errno));
            printf("chdir status - %d\n", i);
            char *wd = (char *)malloc(sizeof (char) * 400);
            pwd = getwd(wd);
            printf("%s\n", wd);
            free(wd);
        }
	}
    return (1);
}