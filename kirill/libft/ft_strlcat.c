/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:43:24 by kirill            #+#    #+#             */
/*   Updated: 2020/11/12 15:45:01 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	j = i;
	if (size - i > 0)
	{
		while (size > i + 1 && src[i - j])
		{
			dst[i] = src[i - j];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src) + j);
}
