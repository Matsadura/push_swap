/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:15:25 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/13 15:03:41 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *
 */
void	swap(t_stack *stack, char name)
{
	t_node	*first;
	t_node	*second;

	if (stack->size <= 1 || stack->name != name)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

/**
 *
 */
void	sa(t_stack *stack, int alert)
{
	swap(stack, 'a');
	if (alert == TRUE)
		ft_printf("sa\n");
}

/**
 *
 */
void	sb(t_stack *stack, int alert)
{
	swap(stack, 'b');
	if (alert == TRUE)
		ft_printf("sb\n");
}

/**
 *
 */
void	ss(t_stack *stackA, t_stack *stackB)
{
	sa(stackA, FALSE);
	sb(stackB, FALSE);
	ft_printf("ss\n");
}
