#include "../minishell.h"

int                 check_num(char *str)
{
    int             i;

    i = 0;
    while (str[i] != '\0')
    {
        if(!(ft_isdigit(str[i])))
            return (0);
        i++;
    }
    return (1);
}

void                 another_exit(char **argv, int *exit_code)
{
    int             count;

    count = count_arguments(argv);
    if (count == 1)
    {
        *exit_code = 0;
        exit(EXIT_SUCCESS);
    }
    else if (count > 2)
    {
        *exit_code = 1;
        printf("exit: too many arguments\n");
        return;
    }
    if (check_num(argv[1]))
    {
        *exit_code = ft_atoi(argv[1]);
        if (*exit_code > 255)
            *exit_code %=256;
        exit(*exit_code);
    }
    else
    {
        printf("numeric argument required\n");
        exit(2);
    }
}