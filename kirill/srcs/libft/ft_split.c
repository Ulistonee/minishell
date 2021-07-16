/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:39:54 by rchalmer          #+#    #+#             */
/*   Updated: 2020/11/23 21:38:17 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	string_quantity(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

static size_t	get_string(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char		**ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**spltd;
	size_t	len;
	size_t	i;
	size_t	len_word;

	if (!s)
		return (NULL);
	i = 0;
	len = string_quantity(s, c);
	spltd = (char **)ft_calloc(sizeof(char *), (len + 1));
	if (spltd == NULL)
		return (NULL);
	while (i < len)
	{
		while (*s && *s == c)
			s++;
		len_word = get_string(s, c);
		if (!(spltd[i++] = ft_substr(s, 0, len_word)))
			return (ft_free(spltd, i - 2));
		while (*s && *s != c)
			s++;
	}
	return (spltd);
}
