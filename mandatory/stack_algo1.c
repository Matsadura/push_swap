/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algo1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:05:23 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/15 16:05:43 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *
 */
int	*stack_to_arr(t_stack *stack)
{
	int	*arr;
	int	len;
	int	i;
	t_node	*cur;

	
	len = lst_len(stack->top);
	arr = malloc(sizeof(int) * len);
	if (arr == NULL)
		return (NULL);
	cur = stack->top;
	i = 0;
	while (cur)
	{
		arr[i] = cur->value;
		cur = cur->next;
		i++;
	}
	return (arr);
}

/**
 *
 */
static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *
 */
int	*sort_array(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				swap_int(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	return (arr);
}

/**
 *
 */
void	index_element_in_arr(int *arr, t_node *top)
{
	t_node	*cur;
	int	i;
	int	len;

	len = lst_len(top);
	i = 0;
	while (i < len)
	{
		cur = top;
		while (cur)
		{
			if (cur->value == arr[i])
			{
				cur->index = i;
				break;
			}
			cur = cur->next;
		}
		i++;
	}
}
