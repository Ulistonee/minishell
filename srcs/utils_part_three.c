/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_part_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:39:28 by rchalmer          #+#    #+#             */
/*   Updated: 2021/07/28 22:39:30 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_free(char **ptr, int res)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (res);
}
