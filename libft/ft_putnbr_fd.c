/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:11:49 by cvirgin           #+#    #+#             */
/*   Updated: 2020/11/11 19:47:15 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	if (n > 0)
		ft_putchar_fd(n % 10 + '0', fd);
	else if (n / 10 == 0 && n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd((n % 10) * -1 + '0', fd);
	}
	else
		ft_putchar_fd((n % 10) * -1 + '0', fd);
}
