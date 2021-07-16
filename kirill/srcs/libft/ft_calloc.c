/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:06:33 by rchalmer          #+#    #+#             */
/*   Updated: 2020/11/23 16:50:44 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str1;
	size_t	sz;

	sz = count * size;
	if (!(str1 = malloc(sz)))
		return (NULL);
	ft_bzero(str1, sz);
	return (str1);
}
