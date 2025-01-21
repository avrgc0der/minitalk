/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:50:44 by enoshahi          #+#    #+#             */
/*   Updated: 2025/01/21 20:46:47 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void 	print_msg(int bit)
{
	if (bit == SIGUSR2)
		ft_putstr_fd("The message has been received!\n", 1);
}

void ascii_to_bit(int pid, char c)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
		bit++;
	}
}

int args_check(int ac, char **av)
{
	int i;

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

int main(int ac, char **av)
{
	int i;
	int pid;
	
	i = 0;
	if (args_check(ac, av))
		return (1);

	pid = ft_atoi(av[1]);
	if(kill(pid, 0) == -1)
	{
		ft_putstr_fd("ERROR: invalid PID or server not running.\n", 1);
		return(1);
	}
	signal(SIGUSR2, print_msg);
	while(av[2][i])
	{
		ascii_to_bit(pid, av[2][i]);
		pause();
		i++;
	}
	ascii_to_bit(pid, '\0');
	pause();
	return(0);
}
