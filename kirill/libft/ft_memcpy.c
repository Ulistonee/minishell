/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:32:11 by kirill            #+#    #+#             */
/*   Updated: 2020/11/12 20:00:09 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char*)dest;
	b = (unsigned char*)src;
	if (src == dest || !n)
		return (dest);
	while (n--)
	{
		*a++ = *b++;
	}
	return (dest);
}
