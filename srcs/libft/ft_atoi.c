/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:14:45 by rchalmer          #+#    #+#             */
/*   Updated: 2020/11/23 21:31:03 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int result;
	int	positive;

	i = 0;
	result = 0;
	positive = 1;
	while ((str[i] == ' ') || (str[i] == '\t') ||
			(str[i] == '\n') || (str[i] == '\v') ||
			(str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		positive = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (positive == 0)
		result = result * (-1);
	return (result);
}
