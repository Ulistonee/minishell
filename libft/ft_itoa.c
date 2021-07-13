/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:00:33 by kirill            #+#    #+#             */
/*   Updated: 2020/11/18 14:38:30 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(int n)
{
	int		k;

	k = 0;
	if (n <= 0)
		k++;
	while (n != 0)
	{
		n = n / 10;
		k++;
	}
	return (k);
}

static char		*copyofint(char *str, int n, int k)
{
	int		i;

	i = 0;
	str[k] = '\0';
	while (k--)
	{
		if (n >= 0)
			str[k] = n % 10 + '0';
		else
		{
			if (n / 10 == 0)
			{
				str[k] = '0' - n % 10;
				str[--k] = '-';
				return (str);
			}
			str[k] = '0' - n % 10;
		}
		n = n / 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		k;

	k = count(n);
	if (!(str = (char*)malloc(sizeof(char) * (k + 1))))
		return (NULL);
	str = copyofint(str, n, k);
	return (str);
}
