/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 00:21:14 by xquah             #+#    #+#             */
/*   Updated: 2024/08/30 11:32:35 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	free(p1);
	free(p2);
}

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