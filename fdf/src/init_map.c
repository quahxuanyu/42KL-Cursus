/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:55:58 by xquah             #+#    #+#             */
/*   Updated: 2024/08/30 13:50:18 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	arr_size(char **lst)
{
	int	i;

	i = -1;
	while (lst[++i])
		continue ;
	free_split(lst);
	return (i);
}

void	get_map_size(t_map *map, int fd)
{
	char *line;

	line = get_next_line(fd);
	map->width = arr_size(ft_split(line, ' '));
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	ft_printf("get_map_size() complete\n");
	ft_printf("width: %i\nheight: %i\n", map->width, map->height);
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

int convert_hex_color(char *color, t_map *map)
{
	//shifts all the until after comma to get the hex
	while (ft_isdigit(*color) || *color == '-' || *color == '+' || *color == ',')
		color++;
	if (*color && *color == 'x')
	{
		map->is_color = 1;
		color++;
		return (ft_atoi_base(color, HEX_BASE));
	}
	return (WHITE);
}

void parse_map(t_map *map, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**split;

	ft_printf("parse_map() start\n");
	i = -1;
	malloc_map(map);
	while (++i < map->height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		j = -1;
		while (split[++j])
		{
			map->z_map[i][j] = ft_atoi(split[j]); // atoi will only do until comma, damn genius
			map->colors[i][j] = convert_hex_color(split[j], map);
		}
		free(line);
		free_split(split);
	}
	ft_printf("parse_map() complete\n");
}

t_map *init_map(char *filename)
{
	int		fd;
	t_map	*map;
	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error();
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit_error();
	ft_printf("init_map() starts\n");
	get_map_size(map, fd);
	fd = open(filename, O_RDONLY);
	parse_map(map, fd);
	close(fd);
	ft_printf("init_map() complete\n");
	return (map);
}

