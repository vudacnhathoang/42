
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MLX42/MLX42.h"
#include <unistd.h>
#include <string.h>
#include "ft_getnextline/get_next_line.h"
#include "Libft/libft.h"
#include <fcntl.h>
#define WIDTH 1920
#define HEIGHT 1020

typedef struct{
	char **map;
	size_t rows;
	size_t cols;
	mlx_texture_t *textures[5];
	mlx_image_t *img[5];
	mlx_t *mlx;
}t_data;


typedef struct{
		int x;
		int y;
}t_player;

void key_handle(mlx_key_data_t keydata, void *param)
{
	mlx_t *mlx = (mlx_t *)param;
	if(keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);


}



void load_texture(t_data *a)
{
	a->textures[0] = mlx_load_png("./images/background.png");
	a->textures[1] = mlx_load_png("./images/sprite.png");
	a->textures[2] = mlx_load_png("./images/wall.png");
	a->textures[3] = mlx_load_png("./images/collect.png");
	a->textures[4] = mlx_load_png("./images/exit.png");

	a->img[0] = mlx_texture_to_image(a->mlx,a->textures[0]);
	a->img[1] = mlx_texture_to_image(a->mlx,a->textures[1]);
	a->img[2] = mlx_texture_to_image(a->mlx,a->textures[2]);
	a->img[3] = mlx_texture_to_image(a->mlx,a->textures[3]);
	a->img[4] = mlx_texture_to_image(a->mlx,a->textures[4]);

}


void render_map(t_data a, t_player *b)
{

size_t j = 0;
size_t i;
int x = 0;
int y = 0;
int x_move = WIDTH/a.cols;
int y_move = HEIGHT/a.rows;
load_texture(&a);
mlx_resize_image(a.img[0],WIDTH, HEIGHT);
mlx_resize_image(a.img[1],x_move, y_move);
mlx_resize_image(a.img[2],x_move, y_move);
mlx_resize_image(a.img[3],x_move, y_move);
mlx_resize_image(a.img[4],x_move, y_move);
mlx_image_to_window(a.mlx, a.img[0], 0,0);

while (j < a.rows)
{	
	i = 0;
	x = 0;
	while(i < a.cols )
		{
		if (a.map[j][i] == '1')
			mlx_image_to_window(a.mlx,a.img[2],x , y);
		else if(a.map[j][i] =='P')
		{	
			b->x = x;
			b->y = y;
			mlx_image_to_window(a.mlx,a.img[1],x , y);
		}
		else if(a.map[j][i] =='E')
			mlx_image_to_window(a.mlx,a.img[4],x , y);
		else if(a.map[j][i] =='C')
			mlx_image_to_window(a.mlx,a.img[3],x , y);
		x +=x_move;
		i++;
		}
	j++;
	y += y_move;
}
}


char *get_map(t_data *a)
{
	int fd;
	char *line;
	char *buffer;
	char *tmp;

	buffer = ft_strdup("");
	tmp = buffer;
	fd = open("maps/map.ber", O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		if(line == NULL)
			break;
		buffer = ft_strjoin(buffer, line);
		free(line);
		free(tmp);
		tmp = buffer;
		line = NULL;
		a->rows++;
	}
	free(line);
	return buffer;
}



int verify_content(char **array, int rows, int *cols)
{
	int i;
 	while(array[*cols]!= NULL)
 	{
		i = 0;
		while(array[*cols][i] != '\0')
			i++;
		if (i != rows)
			return 0;
		*cols= *cols + 1;
 	} 

	return 1;
}

int	verify_map(char **array)
{
	int cols;
	int rows;

	rows = ft_strlen(array[0]);
	cols = 0;

	if (!verify_content(array,rows, &cols))
		{	
			return 0;
		}
	return 1;

}
int main (void)
{
	t_data data;
	t_player knight;

	data.rows = 0;
	data.map = ft_split(get_map(&data),'\n'); // freenout getline
	data.cols = ft_strlen(data.map[0]);
	if(!verify_map(data.map))
		printf("NOT VALID MAP\n");
	else
		printf("VALID MAP\n");
	data.mlx = mlx_init(WIDTH, HEIGHT, "Color Game", true);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	render_map(data, &knight);
	printf("%d %d\n",knight.x,knight.y);
	mlx_key_hook(data.mlx, &key_handle, data.mlx);
	mlx_loop(data.mlx);

	//freenout textrures, images
	//freenout mapu
	return 0;
}
