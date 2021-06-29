#include "minishell.h"

void            my_fork(t_all *all)
{
    pid_t       pid;
    pid_t       wpid;
    int         status;

    pid = fork();
    printf("pid - %d\n", pid);
    if (pid == 0) // дочерний процесс
    {
        printf("%s\n", all->envp_cp.envp_cp[0]);
        exit(EXIT_SUCCESS);
    }
    else if (pid < 0)
    {
        printf("%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else // родительский процесс
        do {
//        int n = 0;
//        while (n++ < 20)
//        {
//            printf("PARENT PROCESS IS WORKING\n");
//        }
            printf("PARENT PROCESS IS WORKING\n");
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
//    {
//        wpid = waitpid(pid, &status, WUNTRACED);
//    }
}