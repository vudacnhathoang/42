/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:28:11 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/09/17 13:00:01 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_handle(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(mlx);
	}
}

void	error_msg(char *msg, t_data *a)
{
	printf("%s\n", msg);
	if (a->map)
		free_map(a->map, a->rows);
	if (a->mlx)
		free_mlx(a);
	exit(EXIT_FAILURE);
}

void	free_map(char **map, int x)
{
	int	j;

	j = 0;
	while (j < x)
	{
		free(map[j]);
		j++;
	}
	free(map);
}

void	free_mlx(t_data *a)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		mlx_delete_texture(a->textures[i]);
		mlx_delete_image(a->mlx,a->img[i]);
		i++;
	}
}
