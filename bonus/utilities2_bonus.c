/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:41:55 by hbettal           #+#    #+#             */
/*   Updated: 2024/02/08 19:04:29 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	ft_abs(double num)
{
	if (num < 0.0)
		return (num *= -1);
	return (num);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	unsigned int	*dst;

	dst = (unsigned int *)data->img_addr;
	dst[y * WIDTH + x] = color;
}
