/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:50:44 by enoshahi          #+#    #+#             */
/*   Updated: 2025/01/27 21:53:37 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	print_msg(int bit)
{
	if (bit == SIGUSR2)
		ft_putstr_fd("The message has been received!\n", 1);
}

void	ascii_to_bit(int pid, char *message)
{
	int	bit;

	while (*message != '\0')
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((*message >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(1000);
			bit--;
		}
		message++;
	}
	bit = 7;
	while (bit >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(1000);
		bit--;
	}
}

int	args_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_putstr_fd("ERROR: try ./client <PID> <Message>\n", 1);
		return (1);
	}
	while (av[1][i])
	{
		if (!ft_isdigit(av[1][i]))
		{
			ft_putstr_fd("ERROR: PID must contain only digits.\n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	pid;

	if (args_check(ac, av))
		return (1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("ERROR: invalid PID.\n", 1);
		return (1);
	}
	if (kill(pid, 0) == -1)
	{
		ft_putstr_fd("ERROR: invalid PID or server not running.\n", 1);
		return (1);
	}
	signal(SIGUSR2, print_msg);
	ascii_to_bit(pid, av[2]);
	return (0);
}
