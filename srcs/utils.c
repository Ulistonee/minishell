#include "minishell.h"

void 			read_envp(t_all *all, char const *envp[])
{
    char		**envp_cp;
    int			n;
    int         i;

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
    all->envp_cp.num_of_lines = n;
}

void            print_arr_2x(char **array)
{
    int         i;

    i = 0;
    while (array[i] != NULL)
    {
        printf("%s\n", array[i]);
        i++;
    }
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