/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:25:35 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/11 17:25:36 by zzaoui           ###   ########.fr       */
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
	int		value;
	struct s_node	*next;
} t_node;

typedef struct s_stack
{
	t_node	*top;
	int	size;
	char	name;
} t_stack;

/* Parsing */
char	**parse_args(int ac, char **av);
int	is_only_space(char *arr);

/* Stack */
void	fill_stack(t_stack *stack, char **args);
void	print_stack(t_stack stack);
void	free_stack(t_stack stack);

#endif /* PUSH_SWAP_H */
