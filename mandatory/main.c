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

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**args;
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac > 1)
	{
		args = parse_args(ac, av);
		stack_b.top = NULL;
		stack_b.size = 0;
		stack_b.name = 'b';
		fill_stack(&stack_a, args, 'a');
		sort_stacks(&stack_a, &stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
		ft_free2d(args);
	}
	return (0);
}
