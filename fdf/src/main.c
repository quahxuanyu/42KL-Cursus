/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:11:40 by xquah             #+#    #+#             */
/*   Updated: 2024/08/30 12:53:54 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_map(t_map *map)
{
	int	i;
	int	j;
	
	i = -1;
	ft_printf("Z Map: witdth - %i   height - %i\n", map->width, map->height);
	while (++i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_printf("%i ", map->z_map[i][j]);
			j++;
		}
		ft_printf("\n");
	}
	ft_printf("\nColour Map:\n");
	i = -1;
	while (++i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_printf("%i ", map->colors[i][j]);
			j++;
		}
		ft_printf("\n");
	}
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		void	*mlx;
		t_data	*fdf;
		t_img	img;
		t_map	*map;
		void	*mlx_win;
		int		zoom;

		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "Xuan's FDF");
		img.img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, // returns the image address
									&img.endian);
		map = init_map(argv[1]);
		fdf = init_data(map, &img);
		//print_map(fdf->map);
		draw_map(fdf);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
		free_map_mem(map);
	}
	exit_error();
}

// int x;
// int y;
// x = 400;
// while (x++ < 800)
// {
// 	my_mlx_pixel_put(&img, x, 200, 0x00FF0000);
// 	my_mlx_pixel_put(&img, x, 600, 0x00FF0000);
// }
// y = 200;
// while (y++ < 600)
// {
// 	my_mlx_pixel_put(&img, 400, y, 0x0000FF00);
// 	my_mlx_pixel_put(&img, 800, y, 0x0000FF00);
// }

// while (x++ < 800)
// {
// 	mlx_pixel_put(mlx, mlx_win, x, 200, 0x00FF0000);
// 	mlx_pixel_put(mlx, mlx_win, x, 600, 0x00FF0000);
// }
// y = 200;
// while (y++ < 600)
// {
// 	mlx_pixel_put(mlx, mlx_win, 400, y, 0x0000FF00);
// 	mlx_pixel_put(mlx, mlx_win, 800, y, 0x0000FF00);
// }
// mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
// mlx_pixel_put(mlx, mlx_win, 250, 250, 0xFF0000);
// mlx_pixel_put(mlx, mlx_win, 100, 100, 0x00FF00);

// int i;
// i = 100;
// while (i++ < 400)
// 	mlx_pixel_put(mlx, mlx_win, i, 300, 0x0000FF);
// mlx_loop(mlx);