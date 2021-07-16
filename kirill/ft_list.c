#include "minishell.h"

void	ft_listadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd *p;

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

t_cmd	*ft_listnew()
{
	t_cmd *new;

	if (!(new = malloc(sizeof(t_cmd))))
		return (NULL);
	/*new->dir.d_back = 0;
	new->dir.d_next = 0;
	new->dir.back = 0;
	new->dir.next = 0;*/
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

t_redirect *new_redirect()
{
	t_redirect *new;

	if (!(new = malloc(sizeof(t_redirect))))
		return (NULL);
	new->redirect = -1;
    new->next = NULL;
	return (new);
}

void	redirect_back(t_redirect **lst, t_redirect *new)
{
	t_redirect *p;

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

t_redirect	*redirect_last(t_redirect *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}