/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:17:26 by rchalmer          #+#    #+#             */
/*   Updated: 2020/11/25 16:08:06 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	size;

	i = 0;
	if ((char *)haystack == NULL)
		return (NULL);
	if (*needle == 0)
		return ((char*)haystack);
	size = ft_strlen(needle);
	while (haystack[i] != '\0')
	{
		if ((i + size) <= len)
			if (!ft_strncmp(&haystack[i], needle, size))
				return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
