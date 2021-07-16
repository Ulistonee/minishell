#include "minishell.h"

void            replace_var(char **key, char *argument)
{
    char        *dup;

//    dup = (char *) malloc(sizeof (char) * ft_strlen(argument));
    free(*key);
    dup = ft_strdup(argument);
    *key = dup;
}

void			add_to_envp(char **envp_cp, char *argument)
{
	char		**res;
	int			n;
	int			count;

	count = count_envp(envp_cp);
	res = (char **) malloc(sizeof (char *) * (count + 2)); // перезаписать number of lines, т.к. массив увеличивается
	n = 0;
	while (envp_cp[n] != NULL)
	{
		res[n] = ft_strdup(envp_cp[n]);
		free(envp_cp[n]);
		n++;
	}
	res[n] = ft_strdup(argument);
	res[n + 1] = NULL;
	free(envp_cp);
	envp_cp = res;
	print_arr_2x(envp_cp);
}

void			add_quotes(char **envp_cp)
{
	int			i;
	int			j;
	int			k;
	char		*equal;
	char		*res;

	i = 0;
	while (envp_cp[i] != NULL)
	{
		equal = ft_strchr(envp_cp[i], '=');
		res = (char *)ft_calloc(ft_strlen(envp_cp[i]) + 3, sizeof(char));
		j = 0;
		k = 0;
		while (envp_cp[i][j] != 0)
		{
			if (&(envp_cp[i][j]) == equal + 1)
			{
				k++;
			}
			res[k] = envp_cp[i][j];
			j++;
			k++;
		}
		res[(equal - envp_cp[i]) + 1] = '"';
		res[ft_strlen(envp_cp[i]) + 1] = '"';
		free(envp_cp[i]);
		envp_cp[i] = res;
		i++;
	}
}

void            sort_envp_cp(char **envp_cp)
{
    int					i;
    int					j;
    char    			*temp;
    char                *temp_2;
    int                 count;

    count = count_envp(envp_cp);
    i = 0;
    while (envp_cp[i] != NULL)
    {
        j = count - 1;
        while (j > i)
        {
            if (ft_strncmp(envp_cp[j - 1], envp_cp[j], (ft_strlen(envp_cp[0]) + 1)) > 0)
            {
                temp = envp_cp[j - 1];
                envp_cp[j - 1] = envp_cp[j];
                envp_cp[j] = temp;
            }
            j--;
        }
        i++;
    }
    i = 0;
    while (envp_cp[i] != NULL)
    {
        temp_2 = envp_cp[i];
        envp_cp[i] = ft_strjoin("declare -x ", envp_cp[i]);
        free(temp_2);
        i++;
    }
}

void			my_export(char *argument, char **envp_cp)
{
	char		**key;

	if (argument == NULL)
	{
		sort_envp_cp(envp_cp);
		add_quotes(envp_cp);
		print_arr_2x(envp_cp);
	}
	else {
		if ((key = check_arg(envp_cp, &(argument)))) {
			replace_var(key, argument);
			print_arr_2x(envp_cp);
		} else
			add_to_envp(envp_cp, argument);
	}
}