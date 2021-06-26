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
}						t_cmd;

typedef struct			s_all
{
	t_cmd				cmd;
	t_envp_cp           envp_cp;
}						t_all;

int						main();
void					my_echo(t_all *all);
void					my_cd(int argc, t_all *all, char const *envp[]);
void					handle_error(char *message, t_all *all);
void                    my_pwd(t_all *all);
void                    my_export(t_all *all);
void			        read_envp(t_all *all, char const *envp[]);

