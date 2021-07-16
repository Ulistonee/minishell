/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:35:35 by kirill            #+#    #+#             */
/*   Updated: 2020/11/06 17:30:20 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	n;

	str = (char*)s;
	n = ft_strlen(s);
	if ((char)c == '\0')
		return (str + n);
	while (n--)
	{
		if (*(str + n) == c)
			return (str + n);
	}
	return (NULL);
}
