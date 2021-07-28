/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:42:30 by rchalmer          #+#    #+#             */
/*   Updated: 2021/07/28 22:42:32 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect4_1(char *line, int *i, t_all **all)
{
	if (line[*i] == '$')
	{
		while (line[++(*i)] != ' ' && line[*i] != '\'' && line[*i] != '\"'
			   && line[*i] != '|' && line[*i] != '>'
			   && line[*i] != '<' && line[*i])
		{
			(*all)->dollar = ft_realloc((*all)->dollar,
					ft_strlen2((*all)->dollar) + 2);
			(*all)->dollar = str_add_to_end((*all)->dollar, line[*i]);
		}
		(*all)->dollar = try_find((*all)->dollar, (*all)->my_env);
		(*all)->old = (*all)->to_red;
		if (!(*all)->to_red)
			(*all)->to_red = ft_strdup("");
		(*all)->to_red = ft_strjoin((*all)->to_red, (*all)->dollar);
		free((*all)->old);
		free((*all)->dollar);
		(*all)->dollar = NULL;
	}
	else
		redirect3_12(line, i, all);
}

void	redirect4_0(char *line, int *i, t_all **all)
{
	while (line[++(*i)] && line[*i] != '\'')
	{
		(*all)->to_red = ft_realloc((*all)->to_red,
				ft_strlen2((*all)->to_red) + 2);
		(*all)->to_red = str_add_to_end((*all)->to_red, line[*i]);
	}
}

void	redirect4(char *line, int *i, t_all **all)
{
	while (line[*i] != ' ' && line[*i] && line[*i] != '>'
		   && line[*i] != '<' && line[*i] != '|')
	{
		if (line[*i] == '\'')
			redirect4_0(line, i, all);
		else if (line[*i] == '\"')
		{
			while (line[++(*i)] && line[*i] != '\"')
			{
				(*all)->to_red = ft_realloc((*all)->to_red,
						ft_strlen2((*all)->to_red) + 2);
				(*all)->to_red = str_add_to_end((*all)->to_red, line[*i]);
			}
		}
		else
			redirect4_1(line, i, all);
	}
}
