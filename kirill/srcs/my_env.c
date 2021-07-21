#include "../minishell.h"

int 				my_env(char **envp_cp, char **argv)
{
    int             count;

    count = count_arguments(argv);
    if (count > 1)
    {
        printf("env: ‘%s’: No such file or directory", argv[1]);
        return (127);
    }
	print_arr_2x(envp_cp);
    return (EXIT_SUCCESS);
}