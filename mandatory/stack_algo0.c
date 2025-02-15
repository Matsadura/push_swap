/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algo0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:53:23 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/15 17:53:30 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *
 */
static int	chunk_size(t_stack *stackA)
{
	int	chunk;

	chunk = 0;
	if (lst_len(stackA->top) <= 100)
		chunk = lst_len(stackA->top) / 6;
	else
		chunk = lst_len(stackA->top) / 12;
	return (chunk);
}

/**
 *
 */
void	fill_stack_b(t_stack *stackA, t_stack *stackB)
{
	int		chunk;
	t_node	*cur;

	chunk = chunk_size(stackA);
	while (lst_len(stackA->top) != 0)
	{
		cur = stackA->top;
		while (cur != NULL)
		{
			if (cur->index < lst_len(stackB->top))
			{
				pb(stackA, stackB);
				ra(stackA, TRUE);
			}
			else if (cur->index < lst_len(stackB->top) + chunk)
				pb(stackA, stackB);
			else
				ra(stackA, TRUE);
			cur = cur->next;
		}
	}
}

/**
 *
 */
void	position_element_in_b(t_stack *stackB)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = stackB->top;
	while (cur != NULL)
	{
		cur->position_b = i;
		i++;
		cur = cur->next;
	}
}

void	below_line_init(t_stack *stackB)
{
	t_node	*cur;
	int		len;

	len = lst_len(stackB->top);
	cur = stackB->top;
	while (cur != NULL)
	{
		if (cur->position_b >= len / 2)
			cur->below_line = TRUE;
		else
			cur->below_line = FALSE;
		cur = cur->next;
	}
}

/**
 *
 */
void	sort_b_to_a(t_stack *stackA, t_stack *stackB)
{
	t_node	*cur;
	int		size;

	size = lst_len(stackB->top);
	cur = stackB->top;
	while (cur->index != size - 1)
	{
		if (cur->below_line == TRUE)
			rrb(stackB, TRUE);
		else
			rb(stackB, TRUE);
	}
	pa(stackA, stackB);
}
