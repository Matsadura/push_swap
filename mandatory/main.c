#include "push_swap.h"

int	main(int ac, char **av)
{
	char **args;
	int	*arr;
	t_stack stackA;
	t_stack stackB;
	unsigned long	i;

	if (ac > 1)
	{
		args = parse_args(ac, av);
		//int	i = 0;
		//while (args[i] != NULL)
		//{
		//	printf("[%s]\n", args[i]);
		//	i++;
		//}
		fill_stack(&stackA, args, 'a');
		arr = stack_to_arr(&stackA);
		arr = sort_array(arr, lst_len(stackA.top));
		index_element_in_arr(arr, stackA.top);
		i = 0;
		while ((int)i < ac - 1)
		{
			printf("arr[%lu] = %d\n", i, arr[i]);
			i++;
		}
		stackB.top = NULL;
		stackB.size = 0;
		stackB.name = 'b';
		fill_stack_b(&stackA, &stackB);
		position_element_in_b(&stackB);
		below_line_init(&stackB);
		//fill_stack(&stackB, args, 'a');
		//fill_stack(&stackB, (char *[]){"9", "8", "7", NULL}, 'b');
//		pb(&stackA, &stackB);
//		pb(&stackA, &stackB);
//		pb(&stackA, &stackB);
		//rr(&stackA, &stackB);
		//rrr(&stackA, &stackB);
		//print_stack(stackA);
		//printf("StackA size: %d\n", stackA.size);
		//only_4(&stackA, &stackB);
		print_stack(stackB);
		//printf("StackA size: %d\n", stackA.size);
//		print_stack(stackB);
//		printf("StackB size: %d\n", stackB.size);
	//	ss(&stackA, &stackB);
	//	print_stack(stackB);
//		sort_small_stack(&stackA, &stackB);
	//	print_stack(stackA);
	//	if (is_sorted(&stackA) == TRUE)
	//		ft_printf("Sorted\n");
	//	else
	//		ft_printf("Not sorted\n");
		print_stack(stackA);
		free_stack(stackA);
		free_stack(stackB);
		ft_free2d(args);
		free(arr);
	}
	return (0);
}
