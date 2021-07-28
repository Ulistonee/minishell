/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:38:20 by rchalmer          #+#    #+#             */
/*   Updated: 2021/07/28 22:38:22 by rchalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_error(int count, char **argv)
{
	if (count > 2)
	{
		write(0, "exit\n", 5);
		write(0, "bash: exit: ", 12);
		write(0, ":too many arguments\n", 28);
	}
	else if (*argv[1] == '-')
	{
		write(0, "exit\n", 5);
		write(0, "bash: exit: ", 12);
		write(0, argv[1], ft_strlen(argv[1]));
		write(0, ":numeric argument required\n", 28);
	}
}

int	check_num(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		while (*str == ' ')
			str++;
		if (*str == '-' || *str == '+')
			str++;
		if (!*str)
			return (0);
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
		return (1);
	}
	return (1);
}

void	exec_exit(char **argv, int *exit_code, int count)
{
	if (check_num(argv[1]))
	{
		*exit_code = ft_atoi(argv[1]);
		printf("exit\n");
		exit((unsigned char)*exit_code);
	}
	else
	{
		if (*argv[1] == '-')
		{
			print_error(count, argv);
			exit(255);
		}
		else
		{
			print_error(count, argv);
			*exit_code = 255;
		}
	}
}

void	my_exit(char **argv, int *exit_code)
{
	int				count;

	count = count_arguments(argv);
	if (count == 1)
	{
		*exit_code = 0;
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	else if (count > 2)
	{
		*exit_code = 1;
		print_error(count, argv);
		return ;
	}
	exec_exit(argv, exit_code, count);
}
