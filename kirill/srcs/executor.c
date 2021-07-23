#include "../minishell.h"

int                scan_redirects(t_redirect *dir, t_fd *std_fd)
{
    t_redirect      *tmp;
    int             file;

//    printf("%d\n", std_fd->std_input);
//    printf("%d\n", std_fd->std_output);
    tmp = dir;
//    while (tmp)
//    {
    if (!(tmp))
    {
        return (EXIT_SUCCESS);
    }
        if (tmp->redirect == 1)
        {
//            printf("check_redirect_1\n");
            if ((file = open(tmp->argv, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
            {
                perror("bash");
                return (1);
            }
//            printf("check_redirect2\n");
            dup2(file, std_fd->std_output);
//            printf("check_redirect3\n");
            //      printf("file - %d\n", file);
            close(file);
        }
        else if (tmp->redirect == 2)
        {
            if ((file = open(tmp->argv, O_WRONLY | O_CREAT | O_APPEND, 0666)) == -1)
            {
                perror("bash");
                return (1);
            }
            dup2(file, std_fd->std_output);
            close(file);
        }
        else if (tmp->redirect == 3)
        {
            if ((file = open(tmp->argv, O_RDONLY, 0666)) == -1)
            {
                perror("bash");
                return (1);
            }
            dup2(file, std_fd->std_input);
            close(file);
        }
    return (0);
}

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
    else if(!(ft_strncmp(tmp->argv[0], "exit", ft_strlen(tmp->argv[0]) + 1)))
        return (1);
    return (0);
}

int                builtins(t_cmd *tmp, char ***envp, int *exit_code)
{
    if(!(ft_strncmp(tmp->argv[0], "echo", ft_strlen(tmp->argv[0]) + 1)))
        *exit_code =  (my_echo(tmp->argv, *exit_code));
    else if(!(ft_strncmp(tmp->argv[0], "cd", ft_strlen(tmp->argv[0]) + 1)))
        *exit_code =  (my_cd(tmp->argv, envp));
    else if(!(ft_strncmp(tmp->argv[0], "pwd", ft_strlen(tmp->argv[0]) + 1)))
        *exit_code =  (my_pwd(tmp->argv));
    else if(!(ft_strncmp(tmp->argv[0], "export", ft_strlen(tmp->argv[0]) + 1)))
        *exit_code = (my_export(tmp->argv, envp));
    else if(!(ft_strncmp(tmp->argv[0], "unset", ft_strlen(tmp->argv[0]) + 1)))
        *exit_code = (my_unset(envp, tmp->argv));
    else if(!(ft_strncmp(tmp->argv[0], "env", ft_strlen(tmp->argv[0]) + 1)))
        *exit_code = my_env(*envp, tmp->argv);
    else if(!(ft_strncmp(tmp->argv[0], "exit", ft_strlen(tmp->argv[0]) + 1)))
        another_exit(tmp->argv, exit_code);
    return (0);
}

void                execute_binary(char *binary_path, char **argv, char ***envp_cp, int *exit_code)
    {
    pid_t           pid;
    pid_t           wpid;
    int             status;

    pid = fork();
    status = 0;
    if (pid < 0)
    {
        printf("%s\n", strerror(errno));
        *exit_code = 71;
    }
    if (pid == 0)
    {
        if (execve(binary_path, argv, *envp_cp) == -1)
        {
            perror("Execve failed");
            *exit_code = 127;
        }
    }
    else
    {
        wpid = waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            *exit_code = WEXITSTATUS(status);
        }
    }
}

void				executor(t_all **all)
{
    pid_t           pid;
    pid_t           wpid;
    int             status;
    t_cmd           *tmp;
    int             fd[2];
    int             backup_stdin;
    int             backup_stdout;

    (*all)->fd.std_input = 0;
    (*all)->fd.std_output = 1;
    dup2((*all)->fd.std_input, 0);
    dup2((*all)->fd.std_output, 1);
    backup_stdin = dup(0);
    backup_stdout = dup(1);
    status = 0;
    tmp = (*all)->cmd;
    if ((*all)->cmd->argv[0] == NULL)
        return;
    if (tmp->next == NULL)
        {
            (*all)->exit_code = scan_redirects(tmp->dir, &((*all)->fd));

            if (is_builtin(tmp) == 1)
            {
                builtins(tmp, &((*all)->my_env), &((*all)->exit_code));

            }
            else
            {
                execute_binary(tmp->way, tmp->argv, &(*all)->my_env, &(*all)->exit_code);

            }
            dup2(backup_stdin, (*all)->fd.std_input); // надо ли закрывать std_input/std_output?
            dup2(backup_stdout, (*all)->fd.std_output);
        }
    else if (tmp->next != NULL)
    {
        while (tmp)
        {
            (*all)->exit_code = scan_redirects(tmp->dir, &(*all)->fd);
            pipe(fd);
            pid = fork();
            if (pid < 0)
            {
                printf("%s\n", strerror(errno));
                (*all)->exit_code = 71;
            }

            else if (pid == 0)
            {
//                if (!(ft_strncmp(tmp->argv[0], "grep", 5)))
//                    tmp->way = ft_strdup("/usr/bin/grep");
                if (tmp->next != NULL)                 // ?
                    dup2(fd[1], (*all)->fd.std_output);
                close(fd[1]);
                close(fd[0]);
                if (is_builtin(tmp) == 1) {
                    builtins(tmp, &((*all)->my_env), &((*all)->exit_code));
                }
                else {
                    if (execve(tmp->way, tmp->argv, (*all)->my_env) == -1)
                    {
                        perror("Execve failed");
                        exit(EXIT_FAILURE);
                    }
                }
            }
            else
            {
                close(fd[1]);
                dup2(fd[0], (*all)->fd.std_input);
                wpid = waitpid(pid, &status, WUNTRACED);
//                    if (WIFEXITED(status))
//                        *exit_code = WEXITSTATUS(status);
                close(fd[0]);
                if (tmp->next == NULL)
                {
                    dup2(backup_stdin, (*all)->fd.std_input);
                    close(backup_stdin); // a где std_output?
                }
            }
//            printf("endless cycle\n");
            tmp = tmp->next;
        }
    }
    close(backup_stdin);
    close(backup_stdout);
}

