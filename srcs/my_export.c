#include "minishell.h"

void            replace_var(char *key, char **envp_cp, char *argument)
{
    char        *dup;

//    dup = (char *) malloc(sizeof (char) * ft_strlen(argument));
    free(key);
    dup = ft_strdup(argument);
    key = dup;
}

void			add_to_envp(t_all *all)
{
	char		**res;
	int			n;

	res = (char **) malloc(sizeof (char *) * (all->envp_cp.num_of_lines + 2)); // перезаписать number of lines, т.к. массив увеличивается
	n = 0;
	while (all->envp_cp.envp_cp[n] != NULL)
	{
		res[n] = ft_strdup(all->envp_cp.envp_cp[n]);
		free(all->envp_cp.envp_cp[n]);
		n++;
	}
	res[n] = ft_strdup(all->cmd.argument);
	res[n + 1] = NULL;
	free(all->envp_cp.envp_cp);
	all->envp_cp.envp_cp = res;
	print_arr_2x(all->envp_cp.envp_cp);
}

void			add_quotes(t_all *all)
{
	int			i;
	int			j;
	int			k;
	char		*equal;
	char		*res;

	i = 0;
	while (all->envp_cp.envp_cp[i] != NULL)
	{
		equal = ft_strchr(all->envp_cp.envp_cp[i], '=');
		res = (char *)ft_calloc(ft_strlen(all->envp_cp.envp_cp[i]) + 3, sizeof(char));
		j = 0;
		k = 0;
		while (all->envp_cp.envp_cp[i][j] != 0)
		{
			if (&(all->envp_cp.envp_cp[i][j]) == equal + 1)
			{
				k++;
			}
			res[k] = all->envp_cp.envp_cp[i][j];
			j++;
			k++;
		}
		res[(equal - all->envp_cp.envp_cp[i]) + 1] = '"';
		res[ft_strlen(all->envp_cp.envp_cp[i]) + 1] = '"';
		all->envp_cp.envp_cp[i] = res;
		i++;
	}
}

void            sort_envp_cp(t_all *all)
{
    int					i;
    int					j;
    char    			*temp;
    char                *temp_2;

    i = 0;
    while (all->envp_cp.envp_cp[i] != NULL)
    {
        j = all->envp_cp.num_of_lines - 1;
        while (j > i)
        {
            if (ft_strncmp(all->envp_cp.envp_cp[j - 1], all->envp_cp.envp_cp[j], (ft_strlen(all->envp_cp.envp_cp[0]) + 1)) > 0)
            {
                temp = all->envp_cp.envp_cp[j - 1];
                all->envp_cp.envp_cp[j - 1] = all->envp_cp.envp_cp[j];
                all->envp_cp.envp_cp[j] = temp;
            }
            j--;
        }
        i++;
    }
    i = 0;
    while (all->envp_cp.envp_cp[i] != NULL)
    {
        temp_2 = all->envp_cp.envp_cp[i];
        all->envp_cp.envp_cp[i] = ft_strjoin("declare -x ", all->envp_cp.envp_cp[i]);
        free(temp_2);
        i++;
    }
}

void			my_export(t_all *all)
{
	char		*key;
	char        *var;

	if (all->cmd.argument == NULL)
	{
		sort_envp_cp(all);
		add_quotes(all);
		print_arr_2x(all->envp_cp.envp_cp);
	}
	else if (all->cmd.argument != NULL)
	{
//	    var = extract_var(all->cmd.argument);
		if ((key = check_arg(all->envp_cp.envp_cp, &(all->cmd.argument))))
        {
//            printf("key - %s\n", key);
//            print_arr_2x(all->envp_cp.envp_cp);
            replace_var(key, all->envp_cp.envp_cp, all->cmd.argument);
//            sort_envp_cp(all);
//            print_arr_2x(all->envp_cp.envp_cp);
        }
		else
			add_to_envp(all);
	}
}