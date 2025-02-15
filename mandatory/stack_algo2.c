/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:24:20 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/15 19:24:21 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *
 */
int	find_max_index(t_node *top)
{
	int	max;

	max = top->index;
	while (top != NULL)
	{
		if (top->index > max)
			max = top->index;
		top = top->next;
	}
	return (max);
}

/**
 *
 */
int	find_position(int max, t_stack *stackB)
{
	t_node *cur;
	int		pos;

	cur = stackB->top;
	pos = 0;
	while (cur != NULL)
	{
		if (cur->index == max)
			break;
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
	int	sizeA;

	sizeA = lst_len(stackA->top);
	if (sizeA == 2)
		only_2(stackA);
	else if (sizeA == 3)
		only_3(stackA);
	else if (sizeA == 4)
		only_4(stackA, stackB);
	else if (sizeA == 5)
		only_5(stackA, stackB);
	else
		sort_large_stack(stackA, stackB);
}

/**
 *
 */
void	sort_large_stack(t_stack *stackA, t_stack *stackB)
{
	int	*arr;
	//t_node	*cur;
	int	i;

	arr = stack_to_arr(stackA);
	sort_array(arr, lst_len(stackA->top));
	index_element_in_arr(arr, stackA->top);
	fill_stack_b(stackA, stackB);
	//cur = stackB->top;
	//while(cur->next != NULL)
	i = lst_len(stackB->top);
	//while(stackB->top->next != NULL)
	while(i > 1)
	{
		position_element_in_b(stackB);
		//below_line_init(stackB);
		sort_b_to_a(stackA, stackB, lst_len(stackB->top));
		//pa(stackA, stackB);
		//cur = cur->next;
		//printf("i: %d\n", i);
		i--;
	}
	if (lst_len(stackB->top) == 1)
		pa(stackA, stackB);
}
