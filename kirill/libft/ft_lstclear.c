/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:06:14 by kirill            #+#    #+#             */
/*   Updated: 2020/11/17 20:31:43 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *clone;

	clone = *lst;
	if (!*lst)
		return ;
	while (clone)
	{
		clone = clone->next;
		del((*lst)->content);
		free(*lst);
		*lst = clone;
	}
}
