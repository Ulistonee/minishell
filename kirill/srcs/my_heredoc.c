#include "../minishell.h"

int	exec_heredoc(char *delimeter, t_all *all)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
	{
		printf("%s\n", strerror(errno));
		return (71);
	}
	else if (pid == 0)
	{
		my_heredoc(delimeter, all);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			return(WEXITSTATUS(status));
		}
		if (WIFSIGNALED(status))
		{
			return (128 + WTERMSIG(status));
		}
	}
	return (EXIT_SUCCESS);
}

int	my_heredoc(char *delimiter, t_all *all)
{
	char	*line;
	int 	fd;

	fd = open(TMP_FILE, O_CREAT | O_RDWR | O_TRUNC, 0666);
//	signal(SIGINT, SIG_DFL);
//	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = readline("> ");
		if (line == NULL || !ft_strncmp(line, delimiter, ft_strlen(line) + 1))
		{
			break;
		}
		if (line)
			line = parse_dollar(line, &all); // нужна функция которая ытаскивает доллар interpret_dollar(&line, ...)
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
	}
	if (line == NULL)
	{
		printf("minishell: warning: here-document is delimited by EOF\n");
		exit(0);
	}
	free(line);
	close(fd);
	exit(0);
}
