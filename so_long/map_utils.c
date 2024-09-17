/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:04:59 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/09/17 11:37:56 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_map(t_data *a, char *mapname)
{
	int		fd;
	char	*line;
	char	*buffer;
	char	*tmp;

	a->rows = 0;
	buffer = ft_strdup("");
	tmp = buffer;
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		buffer = ft_strjoin(buffer, line);
		free(line);
		free(tmp);
		tmp = buffer;
		line = NULL;
		a->rows++;
	}
	free (line);
	return (buffer);
}

char	**duplicate_map(t_data *game)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(game->rows * sizeof(char *));
	while (i < game->rows)
	{
		new[i] = malloc((game->cols + 1) * sizeof(char));
		ft_strlcpy(new[i], game->map[i], game->cols + 1);
		i++;
	}
	return (new);
}

void	map_innit(t_data *a)
{
	a->flood_collected = 0;
	a->flood_ex = 0;
	a->collect = 0;
	a->p_num = 0;
	a->exit = 0;
	a->cols = ft_strlen(a->map[0]);
	a->moves = 0;
}
