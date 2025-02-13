#include "push_swap.h"

int	main(int ac, char **av)
{
	char **args;
	t_stack stackA;
//	t_stack stackB;

//	printf("%d\n", ft_atoi("0000000001"));

	if (ac > 1)
	{
		args = parse_args(ac, av);
		int	i = 0;
		while (args[i] != NULL)
		{
			printf("[%s]\n", args[i]);
			i++;
		}
		fill_stack(&stackA, args, 'a');
	//	fill_stack(&stackB, args, 'b');
	//	print_stack(stackA);
	//	printf("StackA size: %d\n", stackA.size);
	//	print_stack(stackB);
	//	printf("StackB size: %d\n", stackB.size);
	//	ss(&stackA, &stackB);
		print_stack(stackA);
	//	print_stack(stackB);
		free_stack(stackA);
		ft_free2d(args);
	//	free_stack(stackB);
	}
	return (0);
}
