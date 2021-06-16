/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:51:58 by rchalmer          #+#    #+#             */
/*   Updated: 2020/11/23 21:52:08 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_length(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	len = str_length(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		num = (unsigned int)(n * -1);
	}
	else
		num = (unsigned int)n;
	while (num)
	{
		str[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (str);
}
