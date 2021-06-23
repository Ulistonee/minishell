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
	printf("%s", all->cmd.argument);
}