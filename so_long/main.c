
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>
#include <unistd.h>
#include <string.h>
#include "ft_getnextline/get_next_line.h"
#include "Libft/libft.h"
#include <fcntl.h>
#define WIDTH 2560
#define HEIGHT 1600



/*
void render_map(mlx_t* mlx,mlx_image_t* tile)
{
	char *row = "1111111111111111";
	int row_len =strlen(row);
	int t_width = WIDTH/row_len;
	int x = 0;


	while (*row != '\0')
	{
	mlx_image_to_window(mlx, tile,x,0);
	x+= t_width;
	row++;
	}

}
*/

char *get_map(void)
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
	return 0;

return 1;

}
int main (void)
{
	char **map;
	char *new = get_map();
	printf("%s\n",new);
	
	map = ft_split(new, '\n');
	if(!verify_map(map))
		printf("NOT VALID MAP\n");
	else
		printf("VALID MAP\n");

/*
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Color Game", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_texture_t* texture = mlx_load_png("./images/wall.png");
	if (!texture)
		exit(EXIT_FAILURE);
	mlx_image_t* ing = mlx_texture_to_image(mlx, texture);
	if(!ing)
		exit(EXIT_FAILURE);

	//render_map(mlx,ing);
	mlx_loop(mlx);

*/	
	free(new);
	return 0;
}
