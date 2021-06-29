#include "minishell.h"

void            add_to_envp(t_all *all)
{

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

void            my_export(t_all *all)
{
    if (all->cmd.argument == NULL)
    {
        sort_envp_cp(all);
        print_arr_2x(all->envp_cp.envp_cp);
    }
    else if (all->cmd.argument != NULL)
    {
        add_to_envp();
    }
}