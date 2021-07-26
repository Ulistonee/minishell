/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:51:57 by kirill            #+#    #+#             */
/*   Updated: 2021/04/05 20:35:00 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	long long	k;
	long long	s;
	int			i;
	int			n;

	i = 0;
	k = 0;
	n = 1;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			n = -1;
	while (str[i] <= '9' && str[i] >= '0')
	{
		s = k;
		k = k * 10 + (long long)(str[i] - '0');
		if (s > k)
			return (n == 1 ? -1 : 0);
		i++;
	}
	if (k > 2147483647)
		return (-1);
	return ((int)(n == -1 ? -k : k));
}
