#include "../minishell.h"

int                is_builtin(t_cmd *tmp)
{
    if(!(ft_strncmp(tmp->argv[0], "echo", ft_strlen(tmp->argv[0]) + 1)))
        return (1);
    else if(!(ft_strncmp(tmp->argv[0], "cd", ft_strlen(tmp->argv[0]) + 1)))
        return (1);
    else if(!(ft_strncmp(tmp->argv[0], "pwd", ft_strlen(tmp->argv[0]) + 1)))
        return (1);
    else if(!(ft_strncmp(tmp->argv[0], "export", ft_strlen(tmp->argv[0]) + 1)))
        return (1);
    else if(!(ft_strncmp(tmp->argv[0], "unset", ft_strlen(tmp->argv[0]) + 1)))
        return (1);
    else if(!(ft_strncmp(tmp->argv[0], "env", ft_strlen(tmp->argv[0]) + 1)))
        return (1);
    return (0);
}

int                builtins(t_cmd *tmp, char ***envp)
{
    if(!(ft_strncmp(tmp->argv[0], "echo", ft_strlen(tmp->argv[0]) + 1)))
        return (my_echo(tmp->argv));
    else if(!(ft_strncmp(tmp->argv[0], "cd", ft_strlen(tmp->argv[0]) + 1)))
        return (my_cd(tmp->argv, envp));
    else if(!(ft_strncmp(tmp->argv[0], "pwd", ft_strlen(tmp->argv[0]) + 1)))
        return (my_pwd(tmp->argv));
//    else if(!(ft_strncmp(tmp->argv[0], "export", ft_strlen(tmp->argv[0]) + 1)))
//        return(my_export(all));
//    else if(!(ft_strncmp(tmp->argv[0], "unset", ft_strlen(tmp->argv[0]) + 1)))
//        return(my_unset(all));
//    else if(!(ft_strncmp(tmp->argv[0], "env", ft_strlen(tmp->argv[0]) + 1)))
//        return(my_env(all));
    return (0);
}

int                execute_binary(char *binary_path, char **argv, char ***envp_cp)
{
    pid_t           pid;
    pid_t           wpid;
    int             status;

    pid = fork();
    status = 0;
    printf("pid - %d\n", pid);
    if (pid == 0)
    {
        printf("CHILD PROCESS IS WORKING\n");
        execve(binary_path, argv, envp_cp);
    }
    else if (pid < 0)
    {
        printf("%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
    {
            printf("PARENT PROCESS IS WORKING\n");
            wpid = waitpid(pid, &status, WUNTRACED);
    }
}

void				executor(t_all **all)
{
    pid_t           pid;
    pid_t           wpid;
    int             status;
    t_cmd           *tmp;

    status = 0;
    tmp = (*all)->cmd;
    while (tmp)
    {
        if (tmp->next == NULL)
        {
            if (is_builtin(tmp) == 1)
                (*all)->exit_code = builtins(tmp, &(*all)->my_env);
            else
                (*all)->exit_code = execute_binary(tmp->way, tmp->argv, &(*all)->my_env);
        }
////        else if (tmp->next != NULL)
////        {
////            while (tmp->next != NULL)
////            {
////                pipe();
////                pid = fork();
////                if (pid == 0)
////                {
////                    printf("CHILD PROCESS IS WORKING\n");
////                    execve(binary_path, argv, envp_cp);
////                }
////                else if (pid < 0)
////                {
////                    printf("%s\n", strerror(errno));
////                    exit(EXIT_FAILURE);
////                }
////                else
////                {
////                    printf("PARENT PROCESS IS WORKING\n");
////                    wpid = waitpid(pid, &status, WUNTRACED);
////                }
////
////            }
//        }
        tmp = tmp->next;
    }
}

