#include "../minishell.h"

int	call_exec_simple(t_all **all, t_cmd *tmp, int backup_fd[2])
{
	g_status = 0;
	(*all)->exit_code = scan_redirects(tmp->dir, &((*all)->fd), (*all));
	if ((*all)->cmd->argv[0] == NULL || (*all)->exit_code == 1)
	{
		recover_fd(backup_fd, &(*all)->fd);
		return (EXIT_FAILURE);
	}
	if (is_builtin(tmp) == 1)
		builtins(tmp, &((*all)->my_env), &((*all)->exit_code));
	else
		execute_binary(tmp->way, tmp->argv,
			&(*all)->my_env, &(*all)->exit_code);
	dup2(backup_fd[0], (*all)->fd.std_input);
	dup2(backup_fd[1], (*all)->fd.std_output);
	return (EXIT_SUCCESS);
}

void	executor(t_all **all)
{
	t_cmd			*tmp;
	int				backup_fd[2];

	(*all)->fd.std_input = 0;
	(*all)->fd.std_output = 1;
	backup_fd[0] = dup(0);
	backup_fd[1] = dup(1);
	tmp = (*all)->cmd;
	if (tmp->next == NULL)
	{
		if (call_exec_simple(all, tmp, backup_fd) != EXIT_SUCCESS)
			return ;
	}
	else if (tmp->next != NULL)
	{
		while (tmp)
		{
			call_exec_complex(all, tmp, backup_fd);
			tmp = tmp->next;
		}
	}
	close(backup_fd[0]);
	close(backup_fd[1]);
}
