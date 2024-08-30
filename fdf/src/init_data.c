/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:35:36 by xquah             #+#    #+#             */
/*   Updated: 2024/08/30 11:54:29 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*init_data(t_map *map, t_img *img)
{
	t_data *fdf;
	
	fdf = malloc(sizeof(t_data));
	fdf->map = map;
	fdf->img = img;
	if ((W_WIDTH / fdf->map->width / 2) > (W_HEIGHT / fdf->map->height / 2))
		fdf->zoom = (W_WIDTH / fdf->map->width / 2);
	else
		fdf->zoom = (W_HEIGHT / fdf->map->height / 2);
	fdf->shift_x = W_WIDTH / 2;
	fdf->shift_y = (W_HEIGHT - fdf->map->height * fdf->zoom) / 2;
	ft_printf("init_data() Success\n");
	return (fdf);
}