/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:56:11 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/13 17:56:13 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *
 */
void	rra(t_stack *stack, int alert)
{
	reverse_rotate(stack, 'a');
	if (alert == TRUE)
		ft_printf("rra\n");
}

/**
 *
 */
void	rrb(t_stack *stack, int alert)
{
	reverse_rotate(stack, 'b');
	if (alert == TRUE)
		ft_printf("rrb\n");
}

/**
 *
 */
void	rrr(t_stack *stackA, t_stack *stackB)
{
	rra(stackA, FALSE);
	rrb(stackB, FALSE);
}
