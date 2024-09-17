/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:28:09 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/09/17 12:43:20 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_input(t_data *g, int *x, int *y)
{
	static int	keypressed;

	*x = g->k.x;
	*y = g->k.y;
	if (keypressed == 0)
	{
		if (mlx_is_key_down(g->mlx, MLX_KEY_W))
			*y = *y - 1;
		else if (mlx_is_key_down(g->mlx, MLX_KEY_S))
			*y = *y + 1;
		else if (mlx_is_key_down(g->mlx, MLX_KEY_A))
			*x = *x - 1;
		else if (mlx_is_key_down(g->mlx, MLX_KEY_D))
			*x = *x + 1;
		keypressed = 1;
	}
	if (!mlx_is_key_down(g->mlx, MLX_KEY_W)
		&& !mlx_is_key_down(g->mlx, MLX_KEY_S)
		&& !mlx_is_key_down(g->mlx, MLX_KEY_A)
		&&!mlx_is_key_down(g->mlx, MLX_KEY_D))
		keypressed = 0;
}

void	move_sprite(t_data *a, int x, int y)
{
	if (a->map[y][x] == 'E' && a->collect == 0)
		end_game(a);
	else if (a->map[y][x] == 'C')
	{
		a->collect = a->collect - 1;
		a->map[y][x] = 'P';
		a->map[a->k.y][a->k.x] = '0';
		mlx_image_to_window(a->mlx, a->img[0], x * a->x_s, y * a->ys);
		mv(a, x, y);
		a->k.x = x;
		a->k.y = y;
		a->moves++;
		printf("MOVES: %d\n", a->moves);
	}
	else if (a->map[y][x] == '0')
	{
		a->map[y][x] = 'P';
		a->map[a->k.y][a->k.x] = '0';
		mv(a, x, y);
		a->k.x = x;
		a->k.y = y;
		a->moves++;
		printf("MOVES: %d\n", a->moves);
	}
}

void	update(void *param)
{
	t_data	*a;
	int		new_x;
	int		new_y;

	a = (t_data *)param;
	handle_input(a, &new_x, &new_y);
	move_sprite(a, new_x, new_y);
}

void	mv(t_data *a, int x, int y)
{
	mlx_image_to_window(a->mlx, a->img[1], x * a->x_s, y * a->ys);
	mlx_image_to_window(a->mlx, a->img[0], a->k.x * a->x_s, a->k.y * a->ys);
}

void	end_game(t_data *a)
{
	printf("GG, Well done.\n");
	mlx_close_window(a->mlx);
	free(a->map);
	free_mlx(a);
}
