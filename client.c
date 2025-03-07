/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 02:27:19 by ayelasef          #+#    #+#             */
/*   Updated: 2025/03/07 02:28:37 by sboukiou         ###   ########.fr       */
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
	if (ft_atoi(av[1]) <= 0)
	{
		ft_printf("Error: invalid <PID>\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	parse_input(ac, av);
}
