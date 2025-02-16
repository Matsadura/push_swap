/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_funcs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:48:47 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/16 21:48:48 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	init_valid_ops(char ***ops)
{
	static char	*set[] = {
		"ra",
		"rb",
		"rr",
		"pa",
		"pb",
		"rra",
		"rrb",
		"rrr",
		"sa",
		"sb",
		"ss",
		NULL
	};

	*ops = set;
}

int	is_valid_op(char *ops)
{
	char	**set;
	int		i;

	init_valid_ops(&set);
	i = 0;
	while (set[i] != NULL)
	{
		if (ft_strcmp(ops, set[i]) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	all_valid_ops(char **ops)
{
	int	i;

	i = 0;
	while (ops[i] != NULL)
	{
		if (is_valid_op(ops[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	exec_op(t_stack *stackA, t_stack *stackB, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		sa(stackA, 0);
	if (ft_strcmp(op, "sb") == 0)
		sb(stackA, 0);
	if (ft_strcmp(op, "ss") == 0)
		ss(stackA, stackB);
	if (ft_strcmp(op, "pa") == 0)
		pa(stackA, stackB);
	if (ft_strcmp(op, "pb") == 0)
		pb(stackA, stackB);
	if (ft_strcmp(op, "ra") == 0)
		ra(stackA, 0);
	if (ft_strcmp(op, "rb") == 0)
		rb(stackB, 0);
	if (ft_strcmp(op, "rr") == 0)
		rr(stackA, stackB);
	if (ft_strcmp(op, "rra") == 0)
		rra(stackA, 0);
	if (ft_strcmp(op, "rrb") == 0)
		rrb(stackB, 0);
	if (ft_strcmp(op, "rrr") == 0)
		rrr(stackA, stackB);
}

void	exec_ops(t_stack *stackA, t_stack *stackB, char **ops)
{
	int	i;

	i = 0;
	while (ops[i] != NULL)
	{
		exec_op(stackA, stackB, ops[i]);
		i++;
	}
}
