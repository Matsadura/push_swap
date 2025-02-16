/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:34:22 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/14 14:16:35 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/**
 *
 */
int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size == 1)
		return (TRUE);
	if (stack->size == 0)
		return (FALSE);
	tmp = stack->top;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

/**
 *
 */
int	find_min_index(t_stack *stackA, t_stack *stackB)
{
	int		index;
	int		j;
	int		min;
	t_node	*cur;

	(void)stackB;
	index = 1;
	j = 1;
	cur = stackA->top;
	min = cur->value;
	while (cur != NULL)
	{
		if (cur->value < min)
		{
			min = cur->value;
			index = j;
		}
		j++;
		cur = cur->next;
	}
	return (index);
}

/**
 *
 */
void	sort_small_stack(t_stack *stackA, t_stack *stackB)
{
	if (stackA->size == 2)
		only_2(stackA);
	else if (stackA->size == 3)
		only_3(stackA);
	else if (stackA->size == 4)
		only_4(stackA, stackB);
	else if (stackA->size == 5)
		only_5(stackA, stackB);
}
