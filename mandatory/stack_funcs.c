/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:50:23 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/13 10:50:50 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * add_back - Adds the new node 'new' at the end
 *		of the list
 * @stack: The address of a pointer to the first link of
 *		a stack
 * @new: The address of a pointer to the node to be
 *		added to the stack
 */
void	add_back(t_stack *stack, t_node *new)
{
	t_node	*current;

	if (new == NULL)
		return ;
	if (stack->top == NULL)
	{
		stack->top = new;
		stack->size++;
		return ;
	}
	current = stack->top;
	while (current->next)
		current = current->next;
	current->next = new;
	stack->size++;
}

void	add_front(t_stack *stack, t_node *new)
{
	if (new == NULL)
		return ;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
}

/**
 *
 */
void	fill_stack(t_stack *stack, char **args, char name)
{
	int		i;
	t_node	*new;

	i = 0;
	stack->top = 0;
	stack->size = 0;
	stack->name = name;
	while (args[i] != NULL)
	{
		new = malloc(sizeof(t_node));
		if (new == NULL)
			return ;
		new->value = ft_atoi(args[i]);
		new->next = NULL;
		add_back(stack, new);
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
}
