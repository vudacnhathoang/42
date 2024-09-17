/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_redner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:28:04 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/09/16 14:11:59 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_texture(t_data *a)
{
	a->x_s = WIDTH / a->cols;
	a->ys = HEIGHT / a->rows;
	a->textures[0] = mlx_load_png("./images/background.png");
	a->textures[1] = mlx_load_png("./images/sprite.png");
	a->textures[2] = mlx_load_png("./images/wall.png");
	a->textures[3] = mlx_load_png("./images/collect.png");
	a->textures[4] = mlx_load_png("./images/exit.png");
	a->img[0] = mlx_texture_to_image(a->mlx, a->textures[0]);
	a->img[1] = mlx_texture_to_image(a->mlx, a->textures[1]);
	a->img[2] = mlx_texture_to_image(a->mlx, a->textures[2]);
	a->img[3] = mlx_texture_to_image(a->mlx, a->textures[3]);
	a->img[4] = mlx_texture_to_image(a->mlx, a->textures[4]);
	mlx_resize_image(a->img[0], a->x_s, a->ys);
	mlx_resize_image(a->img[1], a->x_s, a->ys);
	mlx_resize_image(a->img[2], a->x_s, a->ys);
	mlx_resize_image(a->img[3], a->x_s, a->ys);
	mlx_resize_image(a->img[4], a->x_s, a->ys);
}

void	render_map(t_data *a)
{
	int	j;
	int	i;

	j = 0;
	load_texture(a);
	while (j < a->rows)
	{
		i = 0;
		while (i < a->cols)
		{
			mlx_image_to_window(a->mlx, a->img[0], i * a->x_s, j * a->ys);
			if (a->map[j][i] == '1')
				mlx_image_to_window(a->mlx, a->img[2], i * a->x_s, j * a->ys);
			else if (a->map[j][i] == 'P')
				mlx_image_to_window(a->mlx, a->img[1], i * a->x_s, j * a->ys);
			else if (a->map[j][i] == 'E')
				mlx_image_to_window(a->mlx, a->img[4], i * a->x_s, j * a->ys);
			else if (a->map[j][i] == 'C')
				mlx_image_to_window(a->mlx, a->img[3], i * a->x_s, j * a->ys);
			i++;
		}
		j++;
	}
}
