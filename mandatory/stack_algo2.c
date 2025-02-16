/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:24:20 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/16 16:50:01 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *
 */
t_node	*greater_index(t_stack *stack, int b_size)
{
	t_node	*cur;

	if (stack == NULL)
		return (NULL);
	cur = stack->top;
	while (cur)
	{
		if (cur->index == (b_size - 1))
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

/**
 *
 */
int	find_position(int max, t_stack *stackB)
{
	t_node	*cur;
	int		pos;

	cur = stackB->top;
	pos = 0;
	while (cur != NULL)
	{
		if (cur->index == max)
			break ;
		pos++;
		cur = cur->next;
	}
	return (pos);
}

/**
 *
 */
void	sort_stacks(t_stack *stackA, t_stack *stackB)
{
	int	size_a;

	size_a = lst_len(stackA->top);
	if (size_a == 2)
		only_2(stackA);
	else if (size_a == 3)
		only_3(stackA);
	else if (size_a == 4)
		only_4(stackA, stackB);
	else if (size_a == 5)
		only_5(stackA, stackB);
	else if (size_a > 5)
		sort_large_stack(stackA, stackB);
}

/**
 *
 */
void	sort_large_stack(t_stack *stackA, t_stack *stackB)
{
	int	*arr;
	int	i;

	arr = stack_to_arr(stackA);
	sort_array(arr, lst_len(stackA->top));
	index_element_in_arr(arr, stackA->top);
	fill_stack_b(stackA, stackB);
	i = lst_len(stackB->top);
	while (i > 1)
	{
		position_element_in_b(stackB);
		below_line_init(stackB);
		sort_b_to_a(stackA, stackB, lst_len(stackB->top));
		i--;
	}
	if (lst_len(stackB->top) == 1)
		pa(stackA, stackB);
	free(arr);
}
