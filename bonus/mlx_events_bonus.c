/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:03:11 by hbettal           #+#    #+#             */
/*   Updated: 2024/02/08 21:19:04 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

int	online_changer(int button, t_mlx *mlx)
{
	if (button == 69)
		mlx->col += 1000;
	else if (button == 78)
		mlx->col -= 1000;
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
	{
		mlx_destroy_window(mlx->unit, mlx->window);
		exit(0);
	}
	if (mlx->zoom < 1.0)
		adjustment = 0.1 * mlx->zoom;
	if (button == 124)
		mlx->r_l += adjustment;
	else if (button == 123)
		mlx->r_l -= adjustment;
	else if (button == 125)
		mlx->u_d += adjustment;
	else if (button == 126)
		mlx->u_d -= adjustment;
	else
		return (online_changer(button, mlx));
	main_drawer(*mlx);
	return (0);
}
