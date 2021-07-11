#include "minishell.h"

/**
**
** @param envs
** @param key
** @return
*/

int             count_envp(char **envp_cp)
{
    int         i;

    i = 0;
    while (envp_cp[i] != NULL)
        i++;
    return (i);
}

char			*check_arg(char **envp_cp, char **key)
{
    char		**tmp;
    int			key_len;
    char        *eq;

    print_arr_2x(envp_cp);
    eq = NULL;
    tmp = envp_cp;
    if (!*key)
        return NULL;
    eq = ft_strchr(*key, '=');
    if (eq)
        (*eq) = '\0';
    key_len = (int)ft_strlen(*key);
    while(*tmp != NULL)
    {
        if (!ft_strncmp(*tmp, *key, key_len) && *(*tmp + key_len) == '=')
        {
            if (eq)
                *eq = '=';
            return (*tmp);
        }
//		if (!ft_strncmp(*tmp, key, key_len + 1))
//			return (*tmp);
        tmp++;
    }
    if (eq)
        *eq = '=';
    return (NULL);
}

char			*get_value(char **envp_cp, char *key)
{
	char		**tmp;
	int			key_len;

	tmp = envp_cp;
	if (!key)
		return NULL;
	key_len = (int)ft_strlen(key);
	while(*tmp != NULL)
	{
		if (!ft_strncmp(*tmp, key, key_len) && *(*tmp + key_len) == '=')
			return (*tmp + key_len + 1);
		if (!ft_strncmp(*tmp, key, key_len + 1))
			return (*tmp + key_len);
		tmp++;
	}
	return (NULL);
}

void 			read_envp(t_all *all, char const *envp[])
{
    char		**envp_cp;
    int			n;

    n = 0;
    while (envp[n] != NULL)
        n++;
    if (!(envp_cp = (char **) malloc(sizeof (char*) * n + 1)))
//		handle_error("Memory allocation error\n", all);
        printf("%s\n", strerror(errno));
    n = 0;
    while (envp[n] != NULL)
    {
        envp_cp[n] = ft_strdup(envp[n]);
        n++;
    }
    envp_cp[n] = NULL;
    all->envp_cp.envp_cp = envp_cp;
}

void            print_arr_2x(char **array)
{
    int         i;

    i = 0;
    printf("\n=================================\n");
    while (array[i] != NULL)
    {
        printf("%s\n", array[i]);
        i++;
    }
    printf("=================================\n");
//    printf("%d\n", i);
//    printf("%s\n", array[i]);
}

void			handle_error(char *message, t_all *all)
{
    ft_putstr_fd("Error\n", 0);
    ft_putstr_fd(message, 0);
//	auto_clear(all);
//	exit(EXIT_FAILURE);
}