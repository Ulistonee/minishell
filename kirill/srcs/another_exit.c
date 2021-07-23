#include "../minishell.h"

int                 check_num(char *str)
{
    int             i;

    i = 0;
    while (str[i] != '\0')
    {
//    	if ((str[0] == '-' || str[0] == '+') || ft_isdigit(str[1]))
//    		i++;
//			if(!(ft_isdigit(str[i])))
//				return (0);
//        i++;
		while (*str == ' ')
			str++;
		if (*str == '-' || *str == '+')
			str++;
		if (!*str)
			return (0);
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
		return (1);
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
		printf("exit\n");
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

//        if (*exit_code > 255)
//            *exit_code %=256;
//        if (*exit_code < 0)
//			*exit_code = 256 + (*exit_code % 256);
		printf("exit\n");
		printf("exit code - %d\n", *exit_code);
        exit((unsigned char)*exit_code);
    }
    else
    {
    	if (*argv[1] == '-')
		{
			printf("exit\n");
			printf("numeric argument required\n");
			exit(255);
		}
    	else
		{
			printf("exit\n");
			printf("numeric argument required\n");
			*exit_code = 255;
		}
    }
}