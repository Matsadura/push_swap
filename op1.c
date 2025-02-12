/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:58:13 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/12 11:58:17 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

/**
 *
 */
void	fill_stack(t_stack *stack, char **args)
{
	int	i;
	t_node *new;

	i = 0;
	stack->top = 0;
	stack->size = 0;
	while (args[i] != NULL)
	{
		new = malloc(sizeof(t_node));
		if (new == NULL)
			return ;
		new->value = ft_atoi(args[i]);
		new->next = stack->top;
		stack->top = new;
		i++;
	}
}

void	print_stack(t_stack stack)
{
	while (stack.top != NULL )
	{
		ft_printf("(%d)\n", stack.top->value);
		stack.top = stack.top->next;
	}
}


void	free_stack(t_stack stack)
{
	t_node	*tmp;

	while (stack.top != NULL)
	{
		tmp = stack.top;
		stack.top = tmp->next;
		free(tmp);
	}
	//free(stack);
}