/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:25:35 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/13 12:01:23 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define FALSE 0
# define TRUE 1
# define STDERR 2

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	char	name;
}	t_stack;

/* Parsing */
char	**parse_args(int ac, char **av);
int		is_only_space(char *arr);

/* Stack Functions */
void	fill_stack(t_stack *stack, char **args, char name);
void	print_stack(t_stack stack);
void	free_stack(t_stack stack);
void	add_back(t_stack *stack, t_node *node);
void	add_front(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
void	swap(t_stack *stack, char name);
void	rotate(t_stack *stack, char name);
void	reverse_rotate(t_stack *stack, char name);

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

#endif /* PUSH_SWAP_H */
