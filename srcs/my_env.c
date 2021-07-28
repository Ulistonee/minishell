/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:38:08 by rchalmer          #+#    #+#             */
/*   Updated: 2021/07/28 22:38:10 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	my_env(char **envp_cp, char **argv)
{
	int				count;

	count = count_arguments(argv);
	if (count > 1)
	{
		printf("env: ‘%s’: No such file or directory", argv[1]);
		return (127);
	}
	print_arr_2x(envp_cp);
	return (EXIT_SUCCESS);
}
