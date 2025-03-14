/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:25:35 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/16 21:40:13 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"

# define FALSE 0
# define TRUE 1
# define STDERR 2

typedef struct s_node
{
	int				value;
	int				index;
	int				position_b;
	int				below_line;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	char	name;
}	t_stack;

typedef struct s_data
{
	t_stack	*s_a;
	t_stack	*s_b;
	char	**args;
}	t_data;

/* Parsing */
char	**parse_args(int ac, char **av);
int		is_only_space(char *arr);

/* Stack Functions */
int		lst_len(t_node *lst);
void	fill_stack(t_stack *stack, char **args, char name);
void	print_stack(t_stack stack);
void	free_stack(t_stack stack);
void	add_back(t_stack *stack, t_node *node);
void	add_front(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
void	swap(t_stack *stack, char name);
void	rotate(t_stack *stack, char name);
void	reverse_rotate(t_stack *stack, char name);
void	sort_stacks(t_stack *stackA, t_stack *stackB);
int		find_max_index(t_node *top);
int		find_position(int max, t_stack *stackB);

/* Large stack functions */
void	fill_stack_b(t_stack *stackA, t_stack *stackB);
void	position_element_in_b(t_stack *stackB);
void	below_line_init(t_stack *stackB);
void	sort_b_to_a(t_stack *stackA, t_stack *stackB, int len);
void	sort_large_stack(t_stack *stackA, t_stack *stackB);

/* Array functions */
int		*stack_to_arr(t_stack *stack);
int		*sort_array(int *arr, int size);
void	index_element_in_arr(int *arr, t_node *top);

/* Stack Operations */
void	sa(t_stack *stack, int alert);
void	sb(t_stack *stack, int alert);
void	ss(t_stack *stackA, t_stack *stackB);
void	pa(t_stack *stackA, t_stack *stackB);
void	pb(t_stack *stackA, t_stack *stackB);
void	ra(t_stack *stack, int alert);
void	rb(t_stack *stack, int alert);
void	rr(t_stack *stackA, t_stack *stackB);
void	rra(t_stack *stack, int alert);
void	rrb(t_stack *stack, int alert);
void	rrr(t_stack *stackA, t_stack *stackB);

/**/
int		is_sorted(t_stack *stack);
int		find_min_index(t_stack *stackA, t_stack *stackB);

/* Small Stack Functions */
void	sort_small_stack(t_stack *stackA, t_stack *stackB);
void	only_2(t_stack *stackA);
void	only_3(t_stack *stackA);
void	only_4(t_stack *stackA, t_stack *stackB);
void	only_5(t_stack *stackA, t_stack *stackB);

t_node	*greater_index(t_stack *stack, int b_size);

/* Checker functions */
char	**read_ops(int fd, t_data vars);
int		all_valid_ops(char **ops);
void	exec_ops(t_stack *stackA, t_stack *stackB, char **ops);

void	is_duplicate(t_stack *stack, t_node *top, t_node *node, char **args);

#endif /* PUSH_SWAP_BONUS_H */
