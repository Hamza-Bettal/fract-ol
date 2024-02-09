/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:29:56 by hbettal           #+#    #+#             */
/*   Updated: 2024/02/08 21:50:54 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fail_handling(void *ptr)
{
	if (!ptr)
		exit(1);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->unit, mlx->window);
	exit(0);
}

int	zooming(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 4)
		mlx->zoom *= 0.96;
	else if (button == 5)
		mlx->zoom *= 1.04;
	else
		return (0);
	main_drawer(*mlx);
	return (0);
}

int	handle_key(int button, t_mlx *mlx)
{
	double	adjustment;

	adjustment = 0.1 / mlx->zoom;
	if (button == 53)
		close_window(mlx);
	else
		return (0);
	main_drawer(*mlx);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	unsigned int	*dst;

	dst = (unsigned int *)data->img_addr;
	dst[y * WIDTH + x] = color;
}
