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

static void	cleanup(t_stack s_a, t_stack s_b, char **args, char **ops)
{
	free_stack(s_a);
	free_stack(s_b);
	ft_free2d(args);
	ft_free2d(ops);
	exit(1);
}

int	main(int ac, char **av)
{
	char	**args;
	char	**ops;
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac > 1)
	{
		args = parse_args(ac, av);
		stack_b.top = NULL;
		stack_b.size = 0;
		stack_b.name = 'b';
		fill_stack(&stack_a, args, 'a');
		ops = read_ops(0);
		if (all_valid_ops(ops) == TRUE)
			exec_ops(&stack_a, &stack_b, ops);
		else
			cleanup(stack_a, stack_b, args, ops);
		if (is_sorted(&stack_a) == TRUE && stack_b.size == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		cleanup(stack_a, stack_b, args, ops);
	}
	return (0);
}
