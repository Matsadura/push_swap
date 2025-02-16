/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_2345.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:16:07 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/14 14:16:49 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/**
 *
 */
void	only_2(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value
		&& stack->name == 'a')
		sa(stack, TRUE);
	else if (stack->top->value > stack->top->next->value
		&& stack->name == 'b')
		sb(stack, TRUE);
}

/**
 *
 */
void	only_3(t_stack *stackA)
{
	int	a;
	int	b;
	int	c;

	a = stackA->top->value;
	b = stackA->top->next->value;
	c = stackA->top->next->next->value;
	if (a > b && b > c && a > c)
	{
		ra(stackA, TRUE);
		sa(stackA, TRUE);
	}
	else if (a > b && b < c && a < c)
		sa(stackA, TRUE);
	else if (a > b && b < c && a > c)
		ra(stackA, TRUE);
	else if (a < b && b > c && a < c)
	{
		rra(stackA, TRUE);
		sa(stackA, TRUE);
	}
	else if (a < b && b > c && a > c)
		rra(stackA, TRUE);
}

/**
 *
 */
void	only_4(t_stack *stackA, t_stack *stackB)
{
	while (find_min_index(stackA, stackB) != 1)
	{
		if (find_min_index(stackA, stackB) > 2)
			rra(stackA, TRUE);
		else if (find_min_index(stackA, stackB) < 3)
			ra(stackA, TRUE);
	}
	pb(stackA, stackB);
	only_3(stackA);
	pa(stackA, stackB);
}

/**
 *
 */
void	only_5(t_stack *stackA, t_stack *stackB)
{
	int	min_index;

	min_index = find_min_index(stackA, stackB);
	while (min_index != 1)
	{
		if (min_index > 2)
			rra(stackA, TRUE);
		else if (min_index < 4)
			ra(stackA, TRUE);
		min_index = find_min_index(stackA, stackB);
	}
	pb(stackA, stackB);
	only_4(stackA, stackB);
	pa(stackA, stackB);
}
