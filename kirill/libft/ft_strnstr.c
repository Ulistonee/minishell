/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:31:19 by kirill            #+#    #+#             */
/*   Updated: 2020/11/21 17:29:49 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == *little)
		{
			j = 1;
			while (big[i + j] == little[j] && little[j] != '\0' && i + j < len)
				j++;
			if (little[j] == '\0')
				return ((char*)&big[i]);
		}
		i++;
	}
	return (NULL);
}
