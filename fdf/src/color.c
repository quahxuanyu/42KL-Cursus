/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:17:05 by xquah             #+#    #+#             */
/*   Updated: 2024/09/08 15:11:15 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	calc_percentage(int start, int end, int current)
{
	if (end != start)
		return ((double)(current - start) / (double)(end - start));
	return (1.0);
}

int	calc_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	calc_z_color(t_data *fdf, int height)
{
	double	percentage;

	percentage = calc_percentage(fdf->map->min_z, fdf->map->max_z, height);
	if (percentage < 0.1)
		return (N_PINK);
	else if (percentage < 0.3)
		return (N_ORANGE);
	else if (percentage < 0.5)
		return (N_YELLOW);
	else if (percentage < 0.7)
		return (N_BLUE);
	else
		return (N_PURPLE);
}

int	calculate_color(t_point *start, t_point *current, t_point *end)
{
	int		r;
	int		g;
	int		b;
	double	percentage;

	if (current->color == end->color)
		return (current->color);
	if (ft_abs(end->x - current->x) > ft_abs(end->y - current->y))
		percentage = calc_percentage(start->x, end->x, current->x);
	else
		percentage = calc_percentage(start->y, end->y, current->y);
	r = calc_light((start->color >> RS) & BM, (end->color >> RS) & BM,
			percentage);
	g = calc_light((start->color >> GS) & BM, (end->color >> GS) & BM,
			percentage);
	b = calc_light(start->color & BM, end->color & BM, percentage);
	return ((r << RS) | (g << GS) | b);
}
