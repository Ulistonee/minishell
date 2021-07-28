/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:41:30 by rchalmer          #+#    #+#             */
/*   Updated: 2021/07/28 22:41:31 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_listadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*p;

	if (lst == NULL)
		return ;
	p = *lst;
	if (p == NULL)
	{
		*lst = new;
		return ;
	}
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}

t_cmd	*ft_listnew(void)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->dir = NULL;
	return (new);
}

t_cmd	*ft_listlast(t_cmd *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
