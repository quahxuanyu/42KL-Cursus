/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 00:21:14 by xquah             #+#    #+#             */
/*   Updated: 2024/09/05 15:13:40 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	slope_less_than_one(t_img *img, t_point *current, t_point *end)
{
	int		p;
	int		i;
	int		dy;
	int		dx;
	t_point	start;

	//ft_printf("slope LESS than one start max_z: %i\n", end->z);
	i = -1;
	start = *current;
	dy = end->y - current->y;
	dx = end->x - current->x;
	p = 2 * ft_abs(dy) - ft_abs(dx);
	while (++i < ft_abs(dx))
	{
		my_mlx_pixel_put(img, current->x,
			current->y, calculate_color(&start, current, end));
		current->x += (dx > 0) - (dx < 0);
		if (p < 0)
			p = p + 2 * ft_abs(dy);
		else
		{
			current->y += (dy > 0) - (dy < 0);
			p = p + 2 * ft_abs(dy) - 2 * ft_abs(dx);
		}
	}
}

void	slope_more_than_one(t_img *img, t_point *current, t_point *end)
{
	int		p;
	int		i;
	int		dy;
	int		dx;
	t_point	start;

	//ft_printf("slope MORE than one start max_z: %i\n", end->z);
	i = -1;
	start = *current;
	dy = end->y - current->y;
	dx = end->x - current->x;
	p = 2 * ft_abs(dx) - ft_abs(dy);
	while (++i < ft_abs(dy))
	{
		my_mlx_pixel_put(img, current->x,
			current->y, calculate_color(&start, current, end));
		current->y += (dy > 0) - (dy < 0);
		if (p < 0)
			p = p + 2 * ft_abs(dx);
		else
		{
			current->x += (dx > 0) - (dx < 0);
			p = p + 2 * ft_abs(dx) - 2 * ft_abs(dy);
		}
	}
}

// t_point	*scale(t_point *p)
// {
// 	t_point *scale;
// 	scale = malloc(sizeof(t_point));
// 	*scale = *p;
// 	scale->x *=
// }
void	draw_line(t_img *img, t_point *p1, t_point *p2)
{
	int	dy;
	int	dx;

	dy = p2->y - p1->y;
	dx = p2->x - p1->x;
	//ft_printf("Draw line start \n");
	if (ft_abs(dy) > ft_abs(dx))
		slope_more_than_one(img, p1, p2);
	else
		slope_less_than_one(img, p1, p2);
	free(p1);
	free(p2);
	//ft_printf("Draw line complete\n");
}

/*
void slope_more_than_one(t_img *img, t_point *current, t_point *end)
{
	int	p;
	int	i;
	int dy;
	int dx;
	t_point start;

	i = -1;
	start = *current;
	dy = end->y - current->y;
	dx = end->x - current->x;
	p = 2 * ft_abs(dx) - ft_abs(dy);
	while (++i < ft_abs(dy))
	{
		my_mlx_pixel_put(img, current->x, current->y, current->color);
		if (dy > 0)
			p1->y += 1;
		else
			p1->y -= 1;
		if (p < 0)
			p = p + 2 * ft_abs(dx);
		else
		{
			if (dx > 0)
				p1->x += 1;
			else
				p1->x -= 1;
			p = p + 2 * ft_abs(dx) - 2 * ft_abs(dy);
		}
	}
}*/

/*
void slope_less_than_one(t_img *img, t_point *p1, int dy, int dx)
{
	int p;
	int i;

	i = 0;
	p = 2 * ft_abs(dy) - ft_abs(dx);
	my_mlx_pixel_put(img, p1->x, p1->y, p1->color);
	while (i < ft_abs(dx))
	{
		if (dx > 0)
			p1->x += 1;
		else
			p1->x -= 1;
		if (p < 0)
			p = p + 2 * ft_abs(dy);
		else
		{
			if (dy > 0)
				p1->y += 1;
			else
				p1->y -= 1;
			p = p + 2 * ft_abs(dy) - 2 * ft_abs(dx);
		}
		my_mlx_pixel_put(img, p1->x, p1->y, p1->color);
		i++;
	}
}

void slope_more_than_one(t_img *img, t_point *p1, int dy, int dx)
{
	int p;
	int i;

	i = 0;
	p = 2 * ft_abs(dx) - ft_abs(dy);
	my_mlx_pixel_put(img, p1->x, p1->y, p1->color);
	while (i < ft_abs(dy))
	{
		if (dy > 0)
			p1->y += 1;
		else
			p1->y -= 1;

		if (p < 0)
			p = p + 2 * ft_abs(dx);
		else
		{
			if (dx > 0)
				p1->x += 1;
			else
				p1->x -= 1;
			p = p + 2 * ft_abs(dx) - 2 * ft_abs(dy);
		}
		my_mlx_pixel_put(img, p1->x, p1->y, p1->color);
		i++;
	}
}

// t_point	*scale(t_point *p)
// {
// 	t_point *scale;

// 	scale = malloc(sizeof(t_point));
// 	*scale = *p;
// 	scale->x *=
// }

void	draw_line(t_img *img, t_point *p1, t_point *p2)
{
	int	dy;
	int	dx;

	dy = p2->y - p1->y;
	dx = p2->x - p1->x;
	if (ft_abs(dy) > ft_abs(dx))
		slope_more_than_one(img, p1, dy, dx);
	else
		slope_less_than_one(img, p1, dy, dx);
}

*/