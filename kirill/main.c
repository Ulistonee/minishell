#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "minishell.h"
#include "term.h"
#include "libft/libft.h"

int 	is_number(char *value)
{
	int i;

	i = 0;
	while(value[i] != '\0')
	{
		if (value[i] == '-' || value[i] == '+')
			i++;
		if(!(ft_isdigit(value[i])))
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
	char 	*key;

	tmp_arr = ft_calloc(4, sizeof(char *));
	tmp_arr[0] = ft_strdup("OLDPWD=");
	tmp_str = getcwd(NULL, 0);
	tmp_arr[1] = ft_strjoin("PWD=", tmp_str);
	tmp_arr[2] = increase_sh_level(get_value(*envp, "SHLVL"));
//	add_variables(tmp_arr, envp);
	i = 0;
	while (tmp_arr[i] != NULL)
	{

		if ((key = check_arg(*envp, &tmp_arr[i])))
			replace_var(key, *envp, tmp_arr[i]);
		else
			add_to_envp(envp, tmp_arr[i]);
//		set_value_arr_2x(tmp_arr[i], envp)
//		printf("%s\n", key);
		i++;
	}
	free(tmp_str);
	free(tmp_arr[0]);
	free(tmp_arr[1]);
	free(tmp_arr[2]);
	free(tmp_arr[3]);
	free(tmp_arr);
	return (*envp);
}

int move_probels(char *line, int i)
{
    while (line[i] == ' ')
    {
        i++;
    }
    return (i);
}

void wait_signal(int sign)
{
    if (sign == SIGINT)
    {
        write(1, "\n", 1);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
}

void ctrl_D()
{
    printf("\033[A");
    printf("bash-3.2$ exit\n");
    exit(0);
}

char **copy_env(char **env)
{
    char **dst;
    int  n;

    dst = NULL;
    n = 0;
    while(env[n])
        n++;
    dst = (char**)malloc(sizeof(char*) * (n + 1));
    n = 0;
    while(env[n])
    {
        dst[n] = ft_strdup(env[n]);
        n++;
    }
    dst[n] = NULL;
    return (dst);
}

void         check_fd()
{
    int     fd[9];
    int 	i;

    i = 0;
    while (fd[i] != 0)
	{
    	fd[i] = dup(i);
		printf("leaked fd - %d\n", fd[i]);
//		close(fd[i]);
    	i++;
	}
//    printf("leaked fd - %d\n", fd);
//    close(fd);
}
#include <string.h>

int main(int argc, char const *argv[], char *env[])
{
    char *line;
    struct termios term;
    t_cmd *list;
    t_all *all;

    tcgetattr(0, &term);
    term.c_lflag &= ~(ECHOCTL);
    tcsetattr(0, TCSANOW, &term);
    signal(SIGINT, wait_signal);
    all = malloc(sizeof(t_all));
    all->my_env = copy_env(env);
//	print_arr_2x(all->my_env);
    all->my_env = add_default_variables(&all->my_env);
	//parse_line("cat > 1 vwqc << 123 >", &all);
	// output_all(all);
	// free_all(&all);
	line = readline("bash-3.2$ ");
	if (!line) {
		ctrl_D();
	}
	add_history(line);
	all = malloc(sizeof(t_all));
	all->my_env = copy_env(env);
	all->exit_code = 0;
	all->my_env = add_default_variables(&all->my_env);
//	print_arr_2x(all->my_env);
    parse_line(line, &all);
//    output_all(all);
    executor(&all);
//	printf("status: %d\n", all->exit_code);
    free_all(&all);
    while (1) // исправить функцию на свою
    {
        line = readline("bash-3.2$ ");
        if (!line) {
            ctrl_D();
        }
        add_history(line);
        parse_line(line, &all);
//        output_all(all);
        executor(&all);
//        printf("status: %d\n", all->exit_code);
//		check_fd();
        free_all(&all);
    }
    return (0);
}




















/*#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <term.h>

int putint(int c)
{
    c = (unsigned char)c;
    return (write(1, &c, 1));
}

int main(int argc, char const *argv[])
{
    char str[2000];
    char *term_name = "xterm-256color";
    int l;
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~(ECHO);
    term.c_lflag &= ~(ICANON);
    tgetent(0, term_name);
    char *ks = tgetstr("ks", NULL);
    tputs(ks, 1, &putint);
    char *ke = tgetstr("ke", NULL);
    tputs(ke, 1, &putint);
    char *up = tgetstr("ku", 0);
    char *down = tgetstr("kd", 0);
    tcsetattr(0, TCSANOW, &term);
    do{
        l = read(0, str, 100);
        if (!strcmp(up, str))
            printf("previous\n");
        else if (!strcmp(down, str))
            printf("next\n");
        else
            write(1, str, l);
    }  while (strcmp(str, "\n"));
    write(1, "\n", 1);

    return (0);
}*/