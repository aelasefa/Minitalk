/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:40:52 by ayelasef          #+#    #+#             */
/*   Updated: 2025/03/10 00:40:54 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	char	*msg;

	int (pid), i;
	parse_input(ac, av);
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
