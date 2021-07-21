#include "../minishell.h"

int            check_argv(char *argument)
{
    if (ft_strchr(argument, '='))
    {
        printf("bash: unset: `%s': not a valid identifier\n", argument);
        return (1);
    }
    return (0);
}

int            my_unset(char ***envp_cp, char *argument)
{
    char        **dup;
    int         count;
    char        *dup_var;
    int         i;
    int         j;

    dup_var = NULL;
    count = count_envp(*envp_cp);
    if (check_argv(argument))
        return (1);
    dup = (char **) malloc(sizeof (char *) * count);
    if ((dup_var = check_arg(*envp_cp, &argument)))
    {
        i = 0;
        j = 0;
        while ((*envp_cp)[i] != NULL)
        {
            if ((*envp_cp)[i] == dup_var) {
                i++;
                continue;
            }
            dup[j] = ft_strdup((*envp_cp)[i]);
            i++;
            j++;
        }
        dup[j] = NULL;
        clear_arr_2x(*envp_cp);
        *envp_cp = dup;
    }
    return (EXIT_SUCCESS);
}