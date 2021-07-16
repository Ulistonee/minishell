/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 23:07:49 by rchalmer          #+#    #+#             */
/*   Updated: 2020/11/15 12:46:48 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	unsigned char symb;

	str = (unsigned char *)s;
	symb = (unsigned char)c;
	while (n--)
	{
		if (*str == symb)
			return (str);
		str++;
	}
	return (NULL);
}
