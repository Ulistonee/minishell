#include "minishell.h"

void            my_pwd(void)
{
    char        *pwd;

    pwd = (char *)malloc(sizeof (char) * 50);
    pwd = getwd(pwd);
    printf("%s\n", pwd);
    free(pwd);
}