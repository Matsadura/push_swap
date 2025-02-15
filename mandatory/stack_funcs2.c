/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:16:31 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/15 16:25:28 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * lst_len - Counts the number of nodes in a list
 * @lst: The beginning of the list
 * Return: The length of the list
 */
int	lst_len(t_node *lst)
{
	int		len;
	t_node	*current;

	len = 0;
	if (lst == NULL)
		return (len);
	current = lst;
	while (current)
	{
		current = current->next;
		len++;
	}
	return (len);
}
