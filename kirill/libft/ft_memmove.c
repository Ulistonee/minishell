/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:02:39 by kirill            #+#    #+#             */
/*   Updated: 2020/11/12 20:01:27 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *scopy;
	unsigned char *dcopy;

	scopy = (unsigned char*)src + n - 1;
	dcopy = (unsigned char*)dest + n - 1;
	if (dest > src)
	{
		while (n--)
		{
			*dcopy-- = *scopy--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
