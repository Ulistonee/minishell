#include "minishell.h"

void 				my_env(t_all *all)
{
	print_arr_2x(all->envp_cp.envp_cp);
}