/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:40:43 by rchalmer          #+#    #+#             */
/*   Updated: 2020/11/23 21:29:17 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = 0;
	while (*s)
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if (ptr)
		return (ptr);
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
