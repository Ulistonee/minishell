/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marwin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:32:08 by rchalmer          #+#    #+#             */
/*   Updated: 2021/01/17 18:42:18 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		write(fd, "-", 1);
		num = (unsigned int)(n * (-1));
	}
	else
		num = (unsigned int)n;
	if (num >= 10)
		ft_putnbr_fd((num / 10), fd);
	ft_putchar_fd(num % 10 + '0', fd);
}
