#include "minishell.h"

void            my_export(t_all *all)
{
    pid_t       pid;
    pid_t       wpid;
    int         i;

    pid = fork();
    if (pid == 0)
    {

    }
    else if (pid < 0)
    {
        printf("Forking error\n", strerror(errno));
    }
    else
    {
        wpid = waitpid(pid, &i, WUNTRACED);
    }
}