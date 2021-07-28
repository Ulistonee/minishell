#include "minishell.h"

int	is_number(char *value)
{
	int	i;

	i = 0;
	while (value[i] != '\0')
	{
		if (value[i] == '-' || value[i] == '+')
			i++;
		if (!(ft_isdigit(value[i])))
			return (0);
		i++;
	}
	return (1);
}

char	*increase_sh_level(char *value)
{
	char	*number;
	char	*shlvl;
	int		level;

	if (!is_number(value))
		return (ft_strdup("SHLVL=1"));
	level = ft_atoi(value);
	if (level >= 999)
		return (ft_strdup("SHLVL="));
	if (level < 0)
		return (ft_strdup("SHLVL=0"));
	number = ft_itoa(++level);
	shlvl = ft_strjoin("SHLVL=", number);
	free(number);
	return (shlvl);
}

char	**add_default_variables(char ***envp)
{
	char	**tmp_arr;
	char	*tmp_str;
	int		i;
	char	*key;

	tmp_arr = ft_calloc(4, sizeof(char *));
	tmp_arr[0] = ft_strdup("OLDPWD=");
	tmp_str = getcwd(NULL, 0);
	tmp_arr[1] = ft_strjoin("PWD=", tmp_str);
	tmp_arr[2] = increase_sh_level(get_value(*envp, "SHLVL"));
	i = 0;
	while (tmp_arr[i] != NULL)
	{
		key = check_arg(*envp, &tmp_arr[i]);
		if (key)
			replace_var(key, *envp, tmp_arr[i]);
		else
			add_to_envp(envp, tmp_arr[i]);
		i++;
	}
	free(tmp_str);
	free(tmp_arr[0]);
	free(tmp_arr[1]), free(tmp_arr[2]);
	free(tmp_arr[3]), free(tmp_arr);
	return (*envp);
}

void	signal_handler(int sig_num)
{
	int	stat_loc;

	wait(&stat_loc);
	if (stat_loc == sig_num)
	{
		if (sig_num == SIGINT)
		{
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
		}
		else if (sig_num == SIGQUIT)
			ft_putstr_fd("Quit: 3\n", 1);
		g_status = 128 + sig_num;
	}
	else if (sig_num == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_status = 1;
	}
}

void	ctrl_d(void)
{
	printf("\033[A");
	printf("minishell: exit\n");
	exit(0);
}

char	**copy_env(char **env)
{
	char	**dst;
	int		n;

	dst = NULL;
	n = 0;
	while (env[n])
		n++;
	dst = (char **)malloc(sizeof(char *) * (n + 1));
	n = 0;
	while (env[n])
	{
		dst[n] = ft_strdup(env[n]);
		n++;
	}
	dst[n] = NULL;
	return (dst);
}

void	my_init(t_all **all, char **env)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	*all = malloc(sizeof(t_all));
	(*all)->my_env = copy_env(env);
	(*all)->exit_code = 0;
	g_status = 0;
}

int	main(int argc, char const *argv[], char *env[])
{
	char			*line;
	struct termios	term;
	t_all			*all;

	(void)argc, (void)argv;
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &term);
	my_init(&all, env);
	while (1)
	{
		line = readline("minishell: ");
		if (!line)
			ctrl_d();
		add_history(line);
		signal(SIGQUIT, signal_handler);
		parse_line(line, &all);
		executor(&all);
		if ((g_status == 0 && all->exit_code != 0) || all->cmd->next)
			g_status = all->exit_code;
		free(line);
		free_all(&all);
		signal(SIGQUIT, SIG_IGN);
	}
	return (0);
}
