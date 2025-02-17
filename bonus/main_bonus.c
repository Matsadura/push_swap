/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:37:11 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/16 18:04:00 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	init_stack_b(t_stack *stackB)
{
	stackB->top = NULL;
	stackB->size = 0;
	stackB->name = 'b';
}

static void	cleanup(t_stack s_a, t_stack s_b, char **args, char **ops)
{
	free_stack(s_a);
	free_stack(s_b);
	ft_free2d(args);
	if (ops != NULL)
		ft_free2d(ops);
	exit(1);
}

static void	wrapper(t_data vars)
{
	char	**ops;

	ops = read_ops(0, vars);
	if (all_valid_ops(ops) == TRUE)
		exec_ops(vars.s_a, vars.s_b, ops);
	else
	{
		ft_printf("Error\n");
		cleanup(*(vars.s_a), *(vars.s_b), vars.args, ops);
	}
	if (is_sorted(vars.s_a) == TRUE && vars.s_b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	cleanup(*(vars.s_a), *(vars.s_b), vars.args, ops);
}

static void	init_data(t_data *vars, t_stack *s_a, t_stack *s_b, char **args)
{
	vars->args = args;
	vars->s_a = s_a;
	vars->s_b = s_b;
}

int	main(int ac, char **av)
{
	char	**args;
	t_stack	stack_a;
	t_stack	stack_b;
	t_data	vars;

	if (ac > 1)
	{
		args = parse_args(ac, av);
		init_stack_b(&stack_b);
		fill_stack(&stack_a, args, 'a');
		init_data(&vars, &stack_a, &stack_b, args);
		wrapper(vars);
	}
	return (0);
}
