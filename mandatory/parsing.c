/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:27:01 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/17 16:05:18 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * is_greater_than_intmax - Checks if an element is bigger than INTMAX
 * @args: An array of arrays representing list of arguments
 */
static void	is_greater_than_intmax(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_atol(args[i]) > INT_MAX || ft_atol(args[i]) < INT_MIN)
		{
			ft_dprintf(STDERR, "Error\n");
			ft_free2d(args);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

/**
 * is_duplicate - Checks if there is a duplicate element
 * @args: An array of arrays representing list of arguments
 */
void	is_duplicate(t_stack *stack, t_node *top, t_node *node, char **args)
{
	t_node	*curr;

	if (top == NULL)
		return ;
	curr = top;
	while (curr != NULL)
	{
		if (curr->value == node->value)
		{
			free(node);
			ft_free2d(args);
			free_stack(*(stack));
			ft_dprintf(STDERR, "Error\n");
			exit(1);
		}
		curr = curr->next;
	}
}

/**
 * is_numerical - Checks if all elements are numerical
 * @args: An array of arrays representing list of arguments
 */
static void	is_numerical(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i] != NULL)
	{
		j = 0;
		if ((args[i][j] == '-' || args[i][j] == '+')
		&& (args[i][j + 1] != '\0'
			&& ft_isdigit((int)args[i][j + 1]) == TRUE))
			j++;
		while (args[i][j] != '\0')
		{
			if (ft_isdigit((int)args[i][j]) == FALSE)
			{
				ft_free2d(args);
				ft_dprintf(STDERR, "Error\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

/**
 * join - Joins all elements in an array and splits it using ' '
 * @ac: number of arguments
 * @av: argument vector
 * Return: An array of arrays representing the elements
 */
static char	**join_and_split(int ac, char **av)
{
	int		i;
	char	*tmp;
	char	**args;

	i = 1;
	tmp = NULL;
	while (i < ac)
	{
		if (av[i] == NULL || av[i][0] == '\0'
		|| is_only_space(av[i]) == TRUE)
		{
			ft_dprintf(STDERR, "Error\n");
			free(tmp);
			exit(EXIT_FAILURE);
		}
		tmp = ft_strjoin_gnl(tmp, av[i]);
		tmp = ft_strjoin_gnl(tmp, " ");
		if (tmp == NULL)
			return (NULL);
		i++;
	}
	if (tmp == NULL)
		return (NULL);
	args = ft_split(tmp, ' ');
	return (free(tmp), args);
}

/**
 * parse_args - Parses the command line arguments
 * @ac: number of arguments
 * @av: argument vector
 * Return: An array of arrays representing the elements
 */
char	**parse_args(int ac, char **av)
{
	char	**args;

	args = join_and_split(ac, av);
	if (args == NULL || *args == NULL)
	{
		free(args);
		ft_dprintf(STDERR, "Error\n");
		exit(EXIT_FAILURE);
	}
	is_numerical(args);
	is_greater_than_intmax(args);
	return (args);
}
