#include "../minishell.h"

int	perror_and_return(char *argv)
{
	perror(argv);
	return (1);
}

int	do_redirection(int redirect, char *argv, t_fd *std_fd)
{
	int		file;

	file = 0;
	if (redirect == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (redirect == 2)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else if (redirect == 3)
		file = open(argv, O_RDONLY, 0666);
	if (file == -1)
		return (perror_and_return(argv));
	if (redirect == 1 || redirect == 2)
		dup2(file, std_fd->std_output);
	if (redirect == 3)
		dup2(file, std_fd->std_input);
	close(file);
	return (0);
}

void	tmp_fd(int input_fd, int exit_code)
{
	int	file;

	if (exit_code != EXIT_SUCCESS)
	{
		file = open(TMP_FD, O_RDWR | O_CREAT | O_TRUNC, 0666);
		if (file == -1)
			return ;
		dup2(file, input_fd);
		close(file);
	}
}

void	recover_fd(int backup_fd[2], t_fd *fd)
{
	dup2(backup_fd[0], fd->std_input);
	dup2(backup_fd[1], fd->std_output);
	close(backup_fd[0]);
	close(backup_fd[1]);
}

//void	init_child(t_fd *fd, int excode, t_cmd *tmp, char **env, int fd_pipe[2])
void	init_child(t_all **all, int excode, t_cmd *tmp, int fd_pipe[2])
{
	tmp_fd((*all)->fd.std_input, excode);
	if (tmp->next != NULL)
		dup2(fd_pipe[1], (*all)->fd.std_output);
	close(fd_pipe[1]);
	close(fd_pipe[0]);
	if (is_builtin(tmp) == 1)
	{
		builtins(tmp, &(*all)->my_env, &excode);
		exit(excode);
	}
	else
	{
		if (execve(tmp->way, tmp->argv, (*all)->my_env) == -1)
		{
			write(0, "bash: ", 6);
			perror(tmp->way);
			exit(127);
		}
	}
}

int	scan_redirects(t_redirect *dir, t_fd *std_fd, t_all *all)
{
	t_redirect		*tmp;
	int				file;
	int				exit_code;

	tmp = dir;
	if (!(tmp))
		return (EXIT_SUCCESS);
	while (tmp)
	{
		if (tmp->redirect != 4)
		{
			if (do_redirection(tmp->redirect, tmp->argv, std_fd) != 0)
				return (1);
		}
		else
		{
			exit_code = exec_heredoc(tmp->argv, all);
			if (exit_code == 130)
				exit_code = 1;
			if (exit_code != EXIT_SUCCESS)
				return (exit_code);
			file = open(TMP_FILE, O_RDONLY, 0666);
			dup2(file, std_fd->std_input), close(file), unlink(TMP_FILE);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	is_builtin(t_cmd *tmp)
{
	if (!(ft_strncmp(tmp->argv[0], "echo", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	else if (!(ft_strncmp(tmp->argv[0], "cd", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	else if (!(ft_strncmp(tmp->argv[0], "pwd", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	else if (!(ft_strncmp(tmp->argv[0], "export", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	else if (!(ft_strncmp(tmp->argv[0], "unset", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	else if (!(ft_strncmp(tmp->argv[0], "env", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	else if (!(ft_strncmp(tmp->argv[0], "exit", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	return (0);
}

int	builtins(t_cmd *tmp, char ***envp, int *exit_code)
{
	if (!(ft_strncmp(tmp->argv[0], "echo", ft_strlen(tmp->argv[0]) + 1)))
		*exit_code = (my_echo(tmp->argv));
	else if (!(ft_strncmp(tmp->argv[0], "cd", ft_strlen(tmp->argv[0]) + 1)))
		*exit_code = (my_cd(tmp->argv, envp));
	else if (!(ft_strncmp(tmp->argv[0], "pwd", ft_strlen(tmp->argv[0]) + 1)))
		*exit_code = (my_pwd(tmp->argv));
	else if (!(ft_strncmp(tmp->argv[0], "export", ft_strlen(tmp->argv[0]) + 1)))
		*exit_code = (my_export(tmp->argv, envp));
	else if (!(ft_strncmp(tmp->argv[0], "unset", ft_strlen(tmp->argv[0]) + 1)))
		*exit_code = (my_unset(envp, tmp->argv));
	else if (!(ft_strncmp(tmp->argv[0], "env", ft_strlen(tmp->argv[0]) + 1)))
		*exit_code = my_env(*envp, tmp->argv);
	else if (!(ft_strncmp(tmp->argv[0], "exit", ft_strlen(tmp->argv[0]) + 1)))
		my_exit(tmp->argv, exit_code);
	return (0);
}

void	execute_binary(char *b_path, char **argv, char ***envp, int *excode)
{
	pid_t			pid;
	int				status;

	pid = fork();
	status = 0;
	if (pid < 0)
	{
		printf("%s\n", strerror(errno));
		*excode = 71;
	}
	if (pid == 0)
	{
		execve(b_path, argv, *envp);
		write(0, "bash: ", 6), perror(b_path);
		exit(127);
	}
	else
	{
		if (is_minishell(argv[0]))
			signal(SIGINT, SIG_IGN);
		waitpid(pid, &status, 0);
		signal(SIGINT, signal_handler);
		if (WIFEXITED(status))
			*excode = WEXITSTATUS(status);
	}
}

void	executor(t_all **all)
{
	pid_t			pid;
	int				status;
	t_cmd			*tmp;
	int				fd[2];
	int				backup_fd[2];

	(*all)->fd.std_input = 0;
	(*all)->fd.std_output = 1;
	backup_fd[0] = dup(0), backup_fd[1] = dup(1);
	status = 0;
	tmp = (*all)->cmd;
	if (tmp->next == NULL)
	{
		g_status = 0;
		(*all)->exit_code = scan_redirects(tmp->dir, &((*all)->fd), (*all));
		if ((*all)->cmd->argv[0] == NULL || (*all)->exit_code == 1)
		{
			recover_fd(backup_fd, &(*all)->fd);
			return;
		}
		if (is_builtin(tmp) == 1)
			builtins(tmp, &((*all)->my_env), &((*all)->exit_code));
		else
			execute_binary(tmp->way, tmp->argv, &(*all)->my_env, &(*all)->exit_code);
		dup2(backup_fd[0], (*all)->fd.std_input); // надо ли закрывать std_input/std_output?
		dup2(backup_fd[1], (*all)->fd.std_output);
	}
	else if (tmp->next != NULL)
	{
		while (tmp)
		{
			(*all)->exit_code = scan_redirects(tmp->dir, &(*all)->fd, (*all));
			{
				pipe(fd);
				pid = fork();
				if (pid < 0)
				{
					printf("%s\n", strerror(errno));
					(*all)->exit_code = 71;
				}
				else if (pid == 0)
					init_child(&(*all), (*all)->exit_code, tmp, fd);
				else
				{
					close(fd[ 1]);
					dup2(fd[0], (*all)->fd.std_input);
                    //signal(SIGINT, SIG_IGN);
					pid = waitpid(pid, &status, 0);
                    //signal(SIGINT, signal_handler);
					if (WIFEXITED(status))
						(*all)->exit_code = WEXITSTATUS(status);
					close(fd[0]);
					if (tmp->next == NULL)
						recover_fd(backup_fd, &(*all)->fd); // a где std_output? их здесь нужно закрывать? a где std_output?
				}
			}
			tmp = tmp->next;
		}
	}
	close(backup_fd[0]);
	close(backup_fd[1]);
}

