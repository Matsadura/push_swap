/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:27:01 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/11 19:09:34 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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
static void	is_duplicate(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i] != NULL)
	{
		j = i + 1;
		if (args[j] != NULL && ft_strcmp(args[i], args[j]) == 0)
		{
			ft_dprintf(STDERR, "Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
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
		if (args[i][j] == '-' || args[i][j] == '+')
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
	free(tmp);
	return (args);
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
	//printf("{{%s}\n", args[0]);
	if (args == NULL || *args == NULL)
	{
		free(args);
		ft_dprintf(STDERR, "Error\n");
		exit(EXIT_FAILURE);
	}
	is_numerical(args);
	is_duplicate(args);
	is_greater_than_intmax(args);
	return (args);
}
