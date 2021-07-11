#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <term.h>
#include <string.h>
#include <curses.h>
#include <termcap.h>
#include <stdlib.h>
#include <errno.h>
#include "libft/libft.h"

typedef struct          s_envp_cp
{
    char                **envp_cp;
}                       t_envp_cp;

typedef struct			s_cmd
{
	char				name;
	char				flag;
	char				*argument;
	int                 argc;
}						t_cmd;

typedef struct			s_all
{
	t_cmd				cmd;
	t_envp_cp           envp_cp;
}						t_all;

void			        my_echo(char flag, char *argument);
void			        my_cd(int argc, char *argument, char **envp_cp);
void					handle_error(char *message, t_all *all);
void                    my_pwd(t_all *all);
void                    my_export(t_all *all);
void			        read_envp(t_all *all, char const *envp[]);
void                    my_fork(t_all *all);
void                    print_arr_2x(char **array);
char					*get_value(char **envp_cp, char *key);
void                    my_unset(t_all *all);
char			        *check_arg(char **envp_cp, char **key);
void                    sort_envp_cp(t_all *all);
void 					my_env(t_all *all);
int                     count_envp(char **envp_cp);

