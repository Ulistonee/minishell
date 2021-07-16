/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marwin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:45:17 by rchalmer          #+#    #+#             */
/*   Updated: 2021/01/22 15:41:21 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_length_base(int n, int base)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(unsigned int n, int base)
{
	char			*str;
	int				len;

	len = str_length_base(n, base);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[len - 1] = n % base + (n % base > 9 ? 'a' - 10 : '0');
		n = n / base;
		len--;
	}
	return (str);
}
