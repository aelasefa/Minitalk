/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:29:34 by ayelasef          #+#    #+#             */
/*   Updated: 2025/03/10 02:29:39 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	parse_input(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("Error: ./server\n");
		exit(1);
	}
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	c = 0;
	static int	client_pid = 0;

	(void)context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		bit = 0;
		c = 0;
	}
	if (sig == SIGUSR2)
		c = (c << 1);
	else if (sig == SIGUSR1)
		c = (c << 1) | 1;
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			kill(client_pid, SIGUSR2);
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	parse_input(ac, av);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
}
