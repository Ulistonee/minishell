#include "minishell.h"

//void            promt_multiline()
//{
//
//}

void			my_echo(t_all *all)
{
//    int         n;
//
//    n = 0;
//    if (all->cmd.argument[n] == 27)
//        promt_multiline();
	if (all->cmd.flag == 'n')
		printf("%s", all->cmd.argument);
	else if (all->cmd.argument == NULL)
		printf("");
	else
		printf("%s\n", all->cmd.argument);
}