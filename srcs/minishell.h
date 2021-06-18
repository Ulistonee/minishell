#include <stdio.h>
#include <unistd.h>
#include <term.h>
#include <string.h>
#include <curses.h>
#include <termcap.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct			s_cmd
{
	char				name;
	char				flag;
	char				*argument;
}						t_cmd;

typedef struct			s_all
{
	t_cmd				cmd;
}						t_all;

int						main();
void					my_echo(t_all *all);
void					my_cd(t_all *all, char const *envp[]);

