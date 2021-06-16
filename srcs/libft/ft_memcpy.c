/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:31:45 by rchalmer          #+#    #+#             */
/*   Updated: 2020/11/15 12:42:27 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	else
	{
		while (i < n)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
		return (dst);
	}
}
