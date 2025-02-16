/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:50:04 by zzaoui            #+#    #+#             */
/*   Updated: 2025/02/16 20:50:05 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	free_and_exit(char *line, int fd)
{
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	ft_dprintf(2, "Error\n");
	exit(1);
}

char	**read_ops(int fd)
{
	char	*line;
	char	*tmp;
	char	**ops;

	if (fd < 0)
		return (NULL);
	tmp = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == '\n')
		{
			free(tmp);
			free_and_exit(line, fd);
		}
		tmp = ft_strjoin_gnl(tmp, line);
		free(line);
		line = get_next_line(fd);
		if (tmp == NULL)
			return (NULL);
	}
	if (tmp == NULL)
		return (NULL);
	ops = ft_split(tmp, '\n');
	return (free(tmp), ops);
}
