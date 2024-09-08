/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:35:29 by xquah             #+#    #+#             */
/*   Updated: 2024/09/08 11:47:19 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_data *fdf)
{
	if (!fdf)
		return (4);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	if (fdf->img)
		free(fdf->img);
	free_map_mem(fdf->map);
	free(fdf->mlx);
	free(fdf);
	exit_error();
	return (0);
}