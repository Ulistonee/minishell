#include "minishell.h"

int                is_builtin(t_command *tmp)
{

}

int                builtins(t_all *all)
{
    if(!(ft_strncmp(all->cmd.name, "echo", ft_strlen(all->cmd.name) + 1)))
    {
        return (my_echo(all->cmd.flag, all->cmd.argument));
    }
    else if(!(ft_strncmp(all->cmd.name, "cd", ft_strlen(all->cmd.name) + 1)))
    {
        return (my_cd(all->cmd.argc, all->cmd.argument, all->envp_cp.envp_cp));
    }
    else if(!(ft_strncmp(all->cmd.name, "pwd", ft_strlen(all->cmd.name) + 1)))
    {
        return (my_pwd());
    }
    else if(!(ft_strncmp(all->cmd.name, "export", ft_strlen(all->cmd.name) + 1)))
    {
        return(my_export(all));
    }
    else if(!(ft_strncmp(all->cmd.name, "unset", ft_strlen(all->cmd.name) + 1)))
    {
        return(my_unset(all));
    }
    else if(!(ft_strncmp(all->cmd.name, "env", ft_strlen(all->cmd.name) + 1)))
    {
        return(my_env(all));
    }
    else
        return (0);
}

void                execute_binary(char *binary_path, char **argv, char **envp_cp)
{
    pid_t       pid;
    pid_t       wpid;
    int         status;

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

void				executor(t_all *all, t_command *cmd)
{

    pid_t           pid;
    pid_t           wpid;
    int             status;
    int             fd[2];
    t_command       *tmp;

    status = 0;
    tmp = cmd;
    while (tmp)
    {
        if (tmp->next == NULL)
        {
            if (!(builtins(all)))
                execute_binary(tmp->way, tmp->argv, all->envp_cp.envp_cp);
        }
        else if (tmp->next != NULL)
        {
            while (tmp->next != NULL)
            {
                pipe(fd);
                pid = fork();
                if (pid == 0)
                {
                    dup2(fd[1], 1);
                    close(fd[0]);
                    close(fd[1]);
                    printf("CHILD PROCESS IS WORKING\n");
                    if (!(builtins(all)))
                        execute_binary(tmp->way, tmp->argv, all->envp_cp.envp_cp);
//                    execve(tmp->way, tmp->argv, all->envp_cp.envp_cp);
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
        }
        tmp = tmp->next;
    }
}

int				main(int argc, char **argv, char const *envp[])
{
	t_all		    all;
    t_command       *cmd1;
    t_command       *cmd2;
    t_command       *tmp;

    cmd1 = (t_command*) malloc(sizeof (t_command));
    cmd2 = (t_command*) malloc(sizeof (t_command));
    tmp = cmd1;
    cmd1->way = ft_strdup("/bin/ls");
    cmd1->argv = (char *[3]){"ls", "-la", NULL};
    cmd1->next = cmd2;

    cmd2->way = ft_strdup("/usr/bin/grep");
    cmd2->argv = (char *[3]){"grep", "my", NULL};
    cmd2->next = NULL;

//	all->cmd.name = 'E'; // echo
//	all->cmd.name = "cd"; // cd
//	all->cmd.name = 'P'; // pwd
//  all->cmd.name = 'X'; // export
//  all->cmd.name = 'U'; // unset
//  all->cmd.name = 'N'; // env
//	all->cmd.flag = 'n';
//  all->cmd.argc = 2;
//  all->cmd.argument = ft_strdup("~/Desktop");
//	all->cmd.flag = 'n';
//	all->cmd.argument = "/Users/rchalmer";
//	printf("%s\n", all->cmd.argument);

//	init(&all);
    read_envp(&all, envp);
//    while(readline)
//        parser()
    executor(&all, cmd1);
}
