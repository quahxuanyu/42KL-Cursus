/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:35:29 by xquah             #+#    #+#             */
/*   Updated: 2024/09/08 16:19:40 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_data *fdf)
{
	if (!fdf)
		return (4);
	ft_printf("destroy image\n");
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	ft_printf("destroy window\n");
	mlx_destroy_window(fdf->mlx, fdf->win);
	ft_printf("destroy display\n");
	mlx_destroy_display(fdf->mlx);
	ft_printf("check fdf->img\n");
	ft_printf("map map\n");
	free_map_mem(fdf->map);
	ft_printf("free mlx\n");
	free(fdf->mlx);
	ft_printf("free fdf\n");
	free(fdf);
	exit_error(0);
	return (0);
}
