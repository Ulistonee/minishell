/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:43:32 by kirill            #+#    #+#             */
/*   Updated: 2020/11/17 20:19:44 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newspisok;
	t_list *newelem;

	newspisok = NULL;
	if (lst == NULL && !del && !f)
		return (NULL);
	while (lst)
	{
		newelem = ft_lstnew(f(lst->content));
		if (!newelem)
		{
			ft_lstclear(&newspisok, del);
			return (NULL);
		}
		ft_lstadd_back(&newspisok, newelem);
		lst = lst->next;
	}
	return (newspisok);
}
