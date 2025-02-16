/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:04:22 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/13 15:05:10 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/**
 *
 */
t_node	*pop(t_stack *stack)
{
	t_node	*top;

	if (stack->size == 0)
		return (NULL);
	top = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	return (top);
}

/**
 *
 */
void	pa(t_stack *stackA, t_stack *stackB)
{
	t_node	*top;

	if (stackB->name != 'b' && stackA->name != 'a')
		return ;
	top = pop(stackB);
	if (top != NULL)
		add_front(stackA, top);
}

/**
 *
 */
void	pb(t_stack *stackA, t_stack *stackB)
{
	t_node	*top;

	if (stackB->name != 'b' && stackA->name != 'a')
		return ;
	top = pop(stackA);
	if (top != NULL)
		add_front(stackB, top);
}
