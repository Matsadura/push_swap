/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:34:22 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/14 10:34:31 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *
 */
int	is_sorted(t_stack *stack)
{
	int		min;
	t_node	*tmp;

	tmp = stack->top;
	min = tmp->value;
	while (tmp != NULL)
	{
		if (min > tmp->value)
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
}

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
//void	only_5(t_stack *stackA, t_stack *stackB)
//{
//	
//}
