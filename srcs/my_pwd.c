/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:38:49 by rchalmer          #+#    #+#             */
/*   Updated: 2021/07/28 22:38:51 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	my_pwd(void)
{
	char		*pwd;

	pwd = (char *)malloc(sizeof (char) * 500);
	pwd = getcwd(pwd, 500);
	printf("%s\n", pwd);
	free(pwd);
	return (EXIT_SUCCESS);
}
