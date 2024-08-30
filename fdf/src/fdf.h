/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:57:39 by xquah             #+#    #+#             */
/*   Updated: 2024/08/30 12:50:56 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../libft/libft.h"
#include "macros.h"
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include <math.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_point
{
	int x;
	int y;
	int z;
	int color;
} t_point;

typedef struct s_map
{
	int	width;
	int	height;
	int	**z_map;
	int	**colors;
	int	is_color;
}	t_map;

typedef struct s_data
{
	t_map	*map;
	t_img	*img;
	int		shift_x;
	int		shift_y;
	int		zoom;
}	t_data;

// helper.c
int		ft_abs(int x);
void exit_error(void);
void my_mlx_pixel_put(t_img *data, int x, int y, int color);
void free_split(char **split);
void free_map_mem(t_map *map);

// line_algo.c
void draw_line(t_img *img, t_point *p1, t_point *p2);

//init_map.c
t_map *init_map(char *filename);

//init_data.c
t_data *init_data(t_map *map, t_img *img);

// draw_map.c
void draw_map(t_data *fdf);

#endif