/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:42:50 by rchalmer          #+#    #+#             */
/*   Updated: 2021/07/28 22:42:52 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_equal(char *path, char *env)
{
	int	i;

	i = 0;
	while (env[i] != '\0')
	{
		if (env[i] == '=')
		{
			if (!(ft_strncmp(env, path, i)))
				return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

char	*ft_realloc(char *ptr, size_t size)
{
	char	*new;

	if (!ptr)
	{
		new = (char *)malloc(size * sizeof(char));
		if (!new)
			return (NULL);
		new[0] = '\0';
	}
	else
	{
		if (ft_strlen(ptr) < size)
		{
			new = (char *)malloc(size * sizeof(char));
			if (!new)
				return (NULL);
			new = ft_strcpy(new, ptr);
			free(ptr);
		}
		else
			new = ptr;
	}
	return (new);
}

char	*str_add_to_end(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	str[i] = c;
	str[++i] = '\0';
	return (str);
}

size_t	ft_strlen2(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
