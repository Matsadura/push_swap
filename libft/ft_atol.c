/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:10:03 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/11 13:55:37 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_atoi - convert ASCII string to long integer
 * @str: the string to convert
 * Return: the result long integer
 */
long	ft_atol(const char *str)
{
	long	i;
	long	result;
	long	sign;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - 48;
		if (result < LONG_MIN || result > LONG_MAX)
			return (INT_MAX + 1);
		i++;
	}
	return (result * sign);
}
