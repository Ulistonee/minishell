/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:42:43 by rchalmer          #+#    #+#             */
/*   Updated: 2021/07/28 22:42:44 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void output_all(t_all *all)
{
    int i;
    int n;
    t_cmd *tmp;
    t_redirect *tmp_red;

    i = -1;
    n = 0;
    tmp = all->cmd;
    tmp_red = all->cmd->dir;
    while(tmp)
    {
        printf("------------------------------\n");
        printf("list%d:\n\n", n++);
        while (++i < tmp->count)
        {
            printf("argv[%d] = %s\n", i, tmp->argv[i]);
        }
        printf("argv[%d] = %s\n", i, tmp->argv[i]);
        printf("way - %s\n", tmp->way);
        while(tmp_red)
        {
            printf("redirect = %d\n", tmp_red->redirect);
            printf("argv = %s\n", tmp_red->argv);
            tmp_red = tmp_red->next;
		}
		i = -1;
        printf("\n\n");
        tmp = tmp->next;
        if (tmp != NULL)
		{
			tmp_red = tmp->dir;
		}
        printf("------------------------------\n\n");
    }
}*/

void	init(t_all **all)
{
	(*all)->dollar = NULL;
	(*all)->f = 0;
	(*all)->to_red = NULL;
	(*all)->cmd = ft_listnew();
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = -1;
	free(cmd->way);
	while (++i < cmd->count + 1)
		free(cmd->argv[i]);
	free(cmd->argv);
	free(cmd);
}

void	free_all0(t_all **all)
{
	if ((*all)->dollar)
		free((*all)->dollar);
	if ((*all)->path)
		free((*all)->path);
	if ((*all)->old)
		free((*all)->old);
	if ((*all)->to_red)
		free((*all)->to_red);
}

void	free_all(t_all **all)
{
	t_cmd		*c;
	t_redirect	*r;

	free_all0(all);
	c = (*all)->cmd;
	while (c)
	{
		c = c->next;
		r = (*all)->cmd->dir;
		while (r)
		{
			r = r->next;
			free((*all)->cmd->dir->argv);
			free((*all)->cmd->dir);
			(*all)->cmd->dir = r;
		}
		free_cmd((*all)->cmd);
		(*all)->cmd = c;
	}
}
