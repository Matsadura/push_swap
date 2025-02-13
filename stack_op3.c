/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:05:02 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/13 17:58:03 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *
 */
void	rotate(t_stack *stack, char name)
{
	t_node	*top;

	if (stack == NULL || stack->name != name)
		return ;
	top = pop(stack);
	if (top != NULL)
	{
		top->next = NULL;
		add_back(stack, top);
	}
}

/**
 *
 */
void	reverse_rotate(t_stack *stack, char name)
{
	t_node	*prev;
	t_node	*last;

	if (stack == NULL || stack->name != name)
		return ;
	prev = stack->top;
	while (prev->next->next != NULL)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

/**
 *
 */
void	ra(t_stack *stack, int alert)
{
	rotate(stack, 'a');
	if (alert == TRUE)
		ft_printf("ra\n");
}

/**
 *
 */
void	rb(t_stack *stack, int alert)
{
	rotate(stack, 'b');
	if (alert == TRUE)
		ft_printf("rb\n");
}

/**
 *
 */
void	rr(t_stack *stackA, t_stack *stackB)
{
	ra(stackA, FALSE);
	rb(stackB, FALSE);
	ft_printf("rr\n");
}
