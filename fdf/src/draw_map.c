/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:26:58 by xquah             #+#    #+#             */
/*   Updated: 2024/09/09 17:43:10 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*create_point(int x, int y, t_data *fdf)
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	p->z = fdf->map->z_map[y][x];
	if (fdf->map->is_color)
		p->color = fdf->map->colors[y][x];
	else
		p->color = calc_z_color(fdf, p->z);
	return (p);
}

void	isometric(t_point *p)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = p->x;
	tmp_y = p->y;
	p->x = (tmp_x - tmp_y) * cos(0.52359877559);
	p->y = (tmp_x + tmp_y) * sin(0.52359877559) - p->z;
}

t_point	*trans_point(t_point *p, t_data *fdf)
{
	p->x *= fdf->zoom;
	p->y *= fdf->zoom;
	p->z *= ((double)fdf->zoom / SF);
	if ((fdf->map->max_z - fdf->map->min_z) != 0)
		if ((double)((fdf->map->width + fdf->map->height) / 2)
			/ (double)(fdf->map->max_z - fdf->map->min_z) > 1)
			p->z *= 5;
	isometric(p);
	p->x += fdf->shift_x;
	p->y += fdf->shift_y;
	return (p);
}

void	draw_map(t_data *fdf)
{
	int	x;
	int	y;

	x = 0;
	while (x < fdf->map->width)
	{
		y = 0;
		while (y < fdf->map->height)
		{
			if (x < fdf->map->width - 1)
				draw_line(fdf->img, trans_point(create_point(x, y, fdf), fdf),
					trans_point(create_point(x + 1, y, fdf), fdf));
			if (y < fdf->map->height - 1)
				draw_line(fdf->img, trans_point(create_point(x, y, fdf), fdf),
					trans_point(create_point(x, y + 1, fdf), fdf));
			y++;
		}
		x++;
	}
}
