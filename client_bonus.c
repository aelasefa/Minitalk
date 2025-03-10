/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:41:57 by ayelasef          #+#    #+#             */
/*   Updated: 2025/03/10 00:42:12 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	parse_input(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Error: ./client <PID> \"msg\"\n");
		exit(1);
	}
	if (ft_atoi(av[1]) <= 0 || !check_digit(av[1]))
	{
		ft_printf("Error: invalid <PID>\n");
		exit(1);
	}
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR2)
		ft_printf("🚀the message has been received🚀\n");
}

void	send_msg(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

int	main(int ac, char **av)
{
	char				*msg;
	struct sigaction	sa;

	int (pid), i;
	parse_input(ac, av);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);
	i = 0;
	pid = ft_atoi(av[1]);
	msg = av[2];
	while (msg[i] != '\0')
	{
		send_msg(msg[i], pid);
		i++;
	}
	send_msg('\n', pid);
	send_msg('\0', pid);
	exit(0);
}
