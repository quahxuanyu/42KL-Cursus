/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:28:25 by xquah             #+#    #+#             */
/*   Updated: 2024/08/30 12:50:45 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void exit_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void free_split(char **split)
{
	int j;

	j = 0;
	while (split[j])
		free(split[j++]);
	free(split);
}

void free_map_mem(t_map *map)
{
	int i;

	if (!map)
		return;
	if (map->z_map)
	{
		i = -1;
		while (++i < map->height && map->z_map[i])
			free(map->z_map[i]);
		free(map->z_map);
	}
	if (map->colors)
	{
		i = -1;
		while (++i < map->height && map->colors[i])
			free(map->colors[i]);
		free(map->colors);
	}
	free(map);
}
