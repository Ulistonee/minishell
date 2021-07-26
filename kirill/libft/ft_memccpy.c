/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:16:42 by kirill            #+#    #+#             */
/*   Updated: 2020/11/11 22:13:54 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char*)dest;
	b = (unsigned char*)src;
	i = 0;
	while (i < n && b[i] != (unsigned char)c)
	{
		a[i] = b[i];
		i++;
	}
	if (n == i)
		return (NULL);
	else
	{
		a[i] = b[i];
		i++;
		return (&a[i]);
	}
}
