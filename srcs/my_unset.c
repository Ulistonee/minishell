/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:38:57 by rchalmer          #+#    #+#             */
/*   Updated: 2021/07/28 22:38:59 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_argv(char *argument)
{
	if (ft_strchr(argument, '='))
	{
		printf("bash: unset: `%s': not a valid identifier\n", argument);
		return (1);
	}
	return (0);
}

void	remove_var(char ***envp_cp, char *dup_var)
{
	int		i;
	int		j;
	char	**dup;
	int		count;

	count = count_envp(*envp_cp);
	dup = (char **) malloc(sizeof (char *) * count);
	i = 0;
	j = 0;
	while ((*envp_cp)[i] != NULL)
	{
		if ((*envp_cp)[i] == dup_var)
		{
			i++;
			continue ;
		}
		dup[j] = ft_strdup((*envp_cp)[i]);
		i++;
		j++;
	}
	dup[j] = NULL;
	clear_arr_2x(*envp_cp);
	*envp_cp = dup;
}

int	my_unset(char ***envp_cp, char **argument)
{
	char		*dup_var;
	int			n;

	dup_var = NULL;
	n = 0;
	while (argument[n] != NULL)
	{
		if (check_argv(argument[n]))
			return (EXIT_FAILURE);
		dup_var = check_arg(*envp_cp, &argument[n]);
		if (dup_var)
			remove_var(envp_cp, dup_var);
		n++;
	}
	return (EXIT_SUCCESS);
}
