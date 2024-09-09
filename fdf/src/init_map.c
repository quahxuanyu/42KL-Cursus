/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:55:58 by xquah             #+#    #+#             */
/*   Updated: 2024/09/09 18:20:03 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_map_size(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		exit_error(1);
	map->width = arr_size(ft_split(line, ' '));
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

// line 76: atoi will only do until comma, damn genius
void	parse_map(t_map *map, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**split;

	i = -1;
	malloc_map(map);
	while (++i < map->height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		j = -1;
		while (split[++j])
		{
			map->z_map[i][j] = calc_z_value(ft_atoi(split[j]), map);
			map->colors[i][j] = convert_hex_color(split[j], map);
		}
		if (j > map->width || j < map->width)
			exit_error(EXIT_FAILURE);
		free(line);
		free_split(split);
	}
}

t_map	*init_map(char *filename)
{
	int		fd;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error(EXIT_FAILURE);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit_error(EXIT_FAILURE);
	get_map_size(map, fd);
	fd = open(filename, O_RDONLY);
	parse_map(map, fd);
	close(fd);
	return (map);
}
