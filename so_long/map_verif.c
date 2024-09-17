/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:28:00 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/09/17 12:26:06 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, t_data *a)
{
	char	tile;

	tile = map[y][x];
	if (x < 0 || y < 0 || x >= a->cols || y >= a->rows)
		return ;
	if (tile == '1' || tile == 'V')
		return ;
	if (tile == 'C')
		a->flood_collected++ ;
	if (tile == 'E')
		a->flood_ex++ ;
	map[y][x] = 'V';
	flood_fill(map, x - 1, y, a);
	flood_fill(map, x + 1, y, a);
	flood_fill(map, x, y - 1, a);
	flood_fill(map, x, y + 1, a);
}

int	check_walls(t_data *g)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < g->cols)
	{
		if (g->map[0][i] != '1' || g->map[g->rows - 1][i] != '1')
			return (0);
		i++;
	}
	while (j < g->rows - 1)
	{
		if (g->map[j][0] != '1' || g->map[j][g->cols - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

void	get_loc(t_data *game, int y, int x)
{
	game->k.x = x;
	game->k.y = y;
}

int	check_content(t_data *game)
{
	int	j;
	int	i;

	j = 0;
	while (j < game->rows)
	{
		i = 0;
		while (i < game->cols)
		{
			if (game->map[j][i] == 'P')
			{
				game->p_num = game->p_num + 1;
				get_loc(game, j, i);
			}
			else if (game->map[j][i] == 'C')
				game->collect++;
			else if (game->map[j][i] == 'E')
				game->exit++;
			else if (game->map[j][i] != '1' && game->map[j][i] != '0')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	verify_map(t_data *a)
{
	char	**new;

	map_innit(a);
	if (!check_content(a))
		error_msg("ERROR: Map has invalid characters", a);
	if (a->p_num != 1 || a->collect < 0 || a->exit != 1)
		error_msg("ERROR: Wrong number of players, collectibles or exits", a);
	if (!check_walls(a))
		error_msg("ERROR: No walls on sides.", a);
	new = duplicate_map(a);
	flood_fill(new, a->k.x, a->k.y, a);
	free_map(new, a->rows);
	if (a->flood_ex != 1 || a->flood_collected != a->collect)
		error_msg("ERROR: Map cannot collect all or exit not reachable.", a);
}
