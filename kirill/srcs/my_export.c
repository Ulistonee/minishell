#include "../minishell.h"

int             check_var_validity(char *argument)
{
    if (!ft_strchr(argument, '='))
        return (fail("Please add variable with \"=\"", 0));
    if ((!(ft_isalpha(argument[0])) && argument[0] != '_'))
    {
        printf("export: '%s': not a valid identifier\n", argument);
        return (0);
    }
    return (1);
}

void            sort_array_2x(char **array)
{
    int					i;
    int					j;
    char    			*temp;
    char                *temp_2;
    int                 count;

    count = count_envp(array);
    i = 0;
    while (array[i] != NULL)
    {
        j = count - 1;
        while (j > i)
        {
            if (ft_strncmp(array[j - 1], array[j], (ft_strlen(array[0]) + 1)) > 0)
            {
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
            j--;
        }
        i++;
    }
//    i = 0;
//    while (envp_cp[i] != NULL)
//    {
//        temp_2 = envp_cp[i];
//        envp_cp[i] = ft_strjoin("declare -x ", envp_cp[i]);
//        free(temp_2);
//        i++;
//    }
}

void            output_sorted_env(char **envp_cp)
{
    char	**p;
    char	**p_orig;
    int		i;

    p = copy_arrays_2x(envp_cp);
    p_orig = p;
    sort_array_2x(p);
    while (*p != NULL)
    {
        write(1, "declare -x ", 11);
        i = 0;
        while((*p)[i] != 0 && (*p)[i] != '=')
        {
            write(1, &(*p)[i], 1);
            i++;
        }
        write(1, &(*p)[i++], 1);
        write(1, "\"", 1);
        while((*p)[i]) {
            write(1, &(*p)[i++], 1);
        }
        write(1, "\"\n", 2);
        p++;
    }
    clear_arr_2x(p_orig);
}


void			add_to_envp(char ***envp_cp, char *argument)
{
	char		**res;
	int			n;
	int         count;

	count = count_envp(*envp_cp);
	res = (char **) malloc(sizeof (char *) * (count + 2)); // перезаписать number of lines, т.к. массив увеличивается
	n = 0;
	while ((*envp_cp)[n] != NULL)
	{
		res[n] = ft_strdup((*envp_cp)[n]);
		free((*envp_cp)[n]);
		n++;
	}
	res[n] = ft_strdup(argument);
	res[n + 1] = NULL;
	free(*envp_cp);
	*envp_cp = res;
//	print_arr_2x(*envp_cp);
}


int            replace_var(char *key, char **envp_cp, char *argument)
{
	char **old_line = NULL;
	char *equal;
	char *new_line;

	if (!(new_line = ft_strdup(argument)))
		return EXIT_FAILURE;
	if (!(equal = ft_strchr(new_line, '=')))
		return (fail("Please add variable with \"=\"", 0));
	*equal = 0;
	if ((old_line = check_key(envp_cp, key)))
	{
		*equal = '=';
		free(*old_line);
		*old_line = new_line;
	}
	else
	{
		*equal = '=';
		add_to_envp(&envp_cp, new_line);
		free(new_line);
	}
	return 0;
}

void			add_quotes(char ***envp_cp)
{
	int			i;
	int			j;
	int			k;
	char		*equal;
	char		*res;

	i = 0;
	while ((*envp_cp)[i] != NULL)
	{
		equal = ft_strchr((*envp_cp)[i], '=');
		res = (char *)ft_calloc(ft_strlen((*envp_cp)[i]) + 3, sizeof(char));
		j = 0;
		k = 0;
		while ((*envp_cp)[i][j] != 0)
		{
			if (&((*envp_cp)[i][j]) == equal + 1)
			{
				k++;
			}
			res[k] = (*envp_cp)[i][j];
			j++;
			k++;
		}
		res[(equal - (*envp_cp)[i]) + 1] = '"';
		res[ft_strlen((*envp_cp)[i]) + 1] = '"';
		(*envp_cp)[i] = res;
		i++;
	}
}

int			my_export(char **argv, char ***envp_cp)
{
	char		*key;
	int         count;
    int         i;

	count = count_envp(argv);
    if (count == 1)
        output_sorted_env(*envp_cp);
    i = 1;
	if (count > 1)
	{
	    while (argv[i] != NULL)
	    {
            if (!(check_var_validity(argv[i])))
                return (0);
            if ((key = check_arg(*envp_cp, &(argv[i]))))
                replace_var(key, *envp_cp, argv[i]);
            else
                add_to_envp(envp_cp, argv[i]);
            i++;
        }
	}
    return (1);
}