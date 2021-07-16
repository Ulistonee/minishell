/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marwin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:11:48 by rchalmer          #+#    #+#             */
/*   Updated: 2021/01/25 14:02:05 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(unsigned int n)
{
	if (n < 10)
		return (1);
	return (count_len(n / 10) + 1);
}

char			*ft_itoa_u(unsigned int n)
{
	size_t		len;
	char		*str;

	len = count_len(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, len + 1);
	str[0] = (n == 0) ? '0' : str[0];
	while (len-- && n != 0)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
