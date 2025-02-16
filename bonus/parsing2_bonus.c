/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:13:35 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/12 09:16:53 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/**
 * is_only_space - Checks if the string contains only whitespaces
 * @arr: The string to check
 * Return: True if only spaces, False otherwise
 */
int	is_only_space(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] != ' ' && arr[i] != '\t')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
