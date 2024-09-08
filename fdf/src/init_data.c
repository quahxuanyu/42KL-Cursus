/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:35:36 by xquah             #+#    #+#             */
/*   Updated: 2024/09/08 14:10:44 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*init_data(t_map *map, t_img *img, void *win, void *mlx)
{
	t_data	*fdf;

	fdf = malloc(sizeof(t_data));
	fdf->map = map;
	fdf->win = win;
	fdf->img = img;
	fdf->mlx = mlx;
	if ((W_WIDTH / fdf->map->width / 2) > (W_HEIGHT / fdf->map->height / 2))
		fdf->zoom = (W_WIDTH / fdf->map->width / 2);
	else
		fdf->zoom = (W_HEIGHT / fdf->map->height / 2);
	fdf->shift_x = W_WIDTH / 2;
	fdf->shift_y = (W_HEIGHT - (fdf->map->height * fdf->zoom)) / 2;
	ft_printf("init_data() Success\n");
	return (fdf);
}

/*		
	// // Assuming W_WIDTH and W_HEIGHT are your screen dimensions
	// int width_factor = W_WIDTH / fdf->map->width / 2;
	// int height_factor = W_HEIGHT / fdf->map->height / 2;

	// // Calculate the range of z values
	// float z_range = fdf->map->max_z - fdf->map->min_z;

	// If there's a significant range in z, account for it in the zoom calculation
	// if (z_range > 0)
	// {
	// 	int depth_factor = W_HEIGHT / z_range / 2;

	// 	// Choose the smallest zoom factor to ensure the entire map fits within the screen
	// 	fdf->zoom = (width_factor < height_factor) ? width_factor : height_factor;
	// 	fdf->zoom = (fdf->zoom < depth_factor) ? fdf->zoom : depth_factor;
	// }
	// else
	// {
	// 	// Fall back to the original method if there's no significant z range
	// 	fdf->zoom = (width_factor < height_factor) ? width_factor : height_factor;
	// }*/

/*
	if ((W_WIDTH / fdf->map->width / 2) > (W_HEIGHT / fdf->map->height / 2))
		fdf->zoom = (W_WIDTH / fdf->map->width / 2);
	else
		fdf->zoom = (W_HEIGHT / fdf->map->height / 2);
*/