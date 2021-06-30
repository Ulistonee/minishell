#include "minishell.h"

char			*check_arg(char **envp_cp, char *key)
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
			return (*tmp);
		if (!ft_strncmp(*tmp, key, key_len + 1))
			return (*tmp);
		tmp++;
	}
	return (NULL);
}

void			replace_var(char **envp_cp, char *new_var, char *dup_key)
{
	free(dup_key);
	dup_key = (char *) malloc(sizeof (char) * ft_strlen(new_var) + 1);
	dup_key = new_var;
}


void			add_to_envp(t_all *all)
{
	char		**res;
	int			n;

	res = (char **) malloc(sizeof (char *) * all->envp_cp.num_of_lines + 2);
	n = 0;
	while (all->envp_cp.envp_cp[n] != NULL)
	{
		res[n] = ft_strdup(all->envp_cp.envp_cp[n]);
		n++;
	}
	res[n] = all->cmd.argument;
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

	if (all->cmd.argument == NULL)
	{
		sort_envp_cp(all);
		add_quotes(all);
		print_arr_2x(all->envp_cp.envp_cp);
	}
	else if (all->cmd.argument != NULL)
	{
		if ((key = check_arg(all->envp_cp.envp_cp, all->cmd.argument)))
			replace_var(all->envp_cp.envp_cp, all->cmd.argument, key);
		else
			add_to_envp(all);
	}
}