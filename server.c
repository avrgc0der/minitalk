/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:50:41 by enoshahi          #+#    #+#             */
/*   Updated: 2025/01/26 21:04:54 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	num;

	(void)context;
	num <<= 1;
	if (sig == SIGUSR1)
		num |= 0x01;
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(num, 1);
		if (num == 0)
			kill(info->si_pid, SIGUSR2);
		bit = 0;
		num = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	act;
	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("Error.\n", 1);
		return (1);
	}
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	act.sa_sigaction = &sig_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return(0);
}