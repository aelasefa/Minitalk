/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:03:21 by ayelasef          #+#    #+#             */
/*   Updated: 2025/03/07 07:44:18 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);

}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	long			result;
	long			last_result;

	int (signe), i;
	i = 0;
	signe = 1;
	result = 0;
	last_result = 0;
	while ((str[i] != '\0' && str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (last_result > 2147483647 || last_result < -2147483648)
			return (-1);
		result = result * 10 + str[i] - '0';
		last_result = signe * result;
		i++;
	}
	return (last_result);
}
