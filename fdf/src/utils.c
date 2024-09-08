/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:21:18 by xquah             #+#    #+#             */
/*   Updated: 2024/09/01 01:40:38 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calc_z_value(int z, t_map *map)
{
	if (z < map->min_z)
		map->min_z = z;
	if (z > map->max_z)
		map->max_z = z;
	return (z);
}

// shifts all the until after comma to get the hex
int	convert_hex_color(char *color, t_map *map)
{
	while (ft_isdigit(*color) || *color == '-'
		|| *color == '+' || *color == ',')
		color++;
	if (*color && *color == 'x')
	{
		map->is_color = 1;
		color++;
		return (ft_atoi_base(color, HEX_BASE));
	}
	return (WHITE);
}

void	malloc_map(t_map *map)
{
	int	i;

	map->z_map = malloc(map->height * sizeof(int *));
	map->colors = malloc(map->height * sizeof(int *));
	i = -1;
	while (++i < map->height)
	{
		map->z_map[i] = ft_calloc(map->width, sizeof(int));
		map->colors[i] = ft_calloc(map->width, sizeof(int));
	}
}

int	arr_size(char **lst)
{
	int	i;

	i = -1;
	while (lst[++i])
		continue ;
	free_split(lst);
	return (i);
}
