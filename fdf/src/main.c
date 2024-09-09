/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:11:40 by xquah             #+#    #+#             */
/*   Updated: 2024/09/09 18:20:27 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keycode, t_data *fdf)
{
	if (keycode == ESC_KEY)
		close_window(fdf);
	return (0);
}

int	main(int argc, char *argv[])
{
	void	*mlx;
	t_data	*fdf;
	t_img	img;
	t_map	*map;
	void	*mlx_win;

	if (argc == 2)
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "Xuan's FDF");
		img.img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		map = init_map(argv[1]);
		fdf = init_data(map, &img, mlx_win, mlx);
		draw_map(fdf);
		mlx_hook(fdf->win, 2, (1L << 0), &handle_keypress, fdf);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_hook(mlx_win, 17, 0, &close_window, fdf);
		mlx_loop(mlx);
		free_map_mem(map);
	}
	exit_error(1);
}

// void print_map(t_map *map)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	ft_printf("Z Map: witdth - %i   height - %i\n", map->width, map->height);
// 	while (++i < map->height)
// 	{
// 		j = 0;
// 		while (j <= map->width + 1)
// 		{
// 			ft_printf("%i ", map->z_map[i][j]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 	}
// }
// 	ft_printf("\nColour Map:\n");
// 	i = -1;
// 	while (++i < map->height)
// 	{
// 		j = 0;
// 		while (j < map->width)
// 		{
// 			ft_printf("%i ", map->colors[i][j]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 	}
// }