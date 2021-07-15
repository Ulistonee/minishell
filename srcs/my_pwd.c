#include "minishell.h"

int             my_pwd(t_all *all)
{
    char        *pwd;

    pwd = (char *)malloc(sizeof (char) * 50);
    pwd = getwd(pwd);
    printf("%s\n", pwd);
    free(pwd);
    return (1);
}