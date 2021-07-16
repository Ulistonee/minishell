#include "../minishell.h"

int            my_unset(t_all *all)
{
    char        **dup;
    int         count;
    char        *dup_var;
    int         i;
    int         j;

    dup_var = NULL;
    count = count_envp(all->envp_cp.envp_cp);
    dup = (char **) malloc(sizeof (char *) * count);
    if ((dup_var = check_arg(all->envp_cp.envp_cp, &all->cmd.argument)))
    {
        i = 0;
        j = 0;
        while (all->envp_cp.envp_cp[i] != NULL)
        {
            if (all->envp_cp.envp_cp[i] == dup_var) {
                i++;
                continue;
            }
            dup[j] = ft_strdup(all->envp_cp.envp_cp[i]);
            i++;
            j++;
        }
        free(all->envp_cp.envp_cp); // надо зафришить all.envp_cp[i]
        all->envp_cp.envp_cp = dup;
    }
//    all->envp_cp.num_of_lines--;
    sort_envp_cp(all);
    print_arr_2x(dup);
    return (1);
}