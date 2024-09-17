/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:06:37 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/09/17 13:12:01 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->map = NULL;
}

void	init_game(t_data *a)
{
a->mlx = mlx_init(WIDTH, HEIGHT, "Maze game", true);
	if (!a->mlx)
		exit(EXIT_FAILURE);
	render_map(a);
	mlx_key_hook(a->mlx, &key_handle, a->mlx);
	//mlx_loop_hook(data.mlx, &update, &data);
	mlx_loop(a->mlx);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char *line;
	
	init_data(&data);
	if (argc != 2)
		error_msg("ERROR: no map",&data);
	line = get_map(&data, argv[1]);
	if(line[0]== 0)
	{
		free(line);
		exit(EXIT_FAILURE);
	}
	data.map = ft_split(line,'\n');
	free(line);
	verify_map(&data);
	init_game(&data);
	mlx_terminate(data.mlx);
	return (0);
}
