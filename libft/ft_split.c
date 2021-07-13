/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:33:27 by kirill            #+#    #+#             */
/*   Updated: 2020/11/21 16:08:50 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**mycopy(char **spl, char *s, char c, int n)
{
	int i;
	int count;
	int m;

	i = 0;
	count = 0;
	while (s[i] != '\0' && count < n)
	{
		m = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			spl[count][m] = s[i];
			i++;
			m++;
		}
		spl[count][m] = '\0';
		count++;
	}
	spl[count] = NULL;
	return (spl);
}

static char		**myfree(char **spl, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(spl[i]);
		i++;
	}
	free(spl);
	return (spl);
}

static char		**stroki(char **spl, int n, char c, char *str)
{
	int m;
	int j;

	j = 0;
	while (*str)
	{
		m = 0;
		while (*str == c)
			str++;
		while (*str != c && *str != '\0')
		{
			str++;
			m++;
		}
		if (m != 0)
		{
			if (!(spl[j] = (char*)malloc(sizeof(char) * (m + 1))))
				return (myfree(spl, n));
		}
		j++;
	}
	return (spl);
}

static int		words(char *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	int		n;
	char	**spl;

	if (!s)
		return (NULL);
	n = words((char*)s, c);
	if (!(spl = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	spl = stroki(spl, n, c, (char*)s);
	spl = mycopy(spl, (char*)s, c, n);
	return (spl);
}
