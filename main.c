#include "push_swap.h"

int	main(int ac, char **av)
{
	char **args;
	t_stack stackA;

	if (ac > 1)
	{
		args = parse_args(ac, av);
		int	i = 0;
		while (args[i] != NULL)
		{
			printf("[%s]\n", args[i]);
			i++;
		}
		fill_stack(&stackA, args);
		print_stack(stackA);
		free_stack(stackA);
		ft_free2d(args);
	}
	return (0);
}
