/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:44:16 by hbettal           #+#    #+#             */
/*   Updated: 2024/02/08 19:20:30 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	color_changer(int iter)
{
	int	red;
	int	green;
	int	blue;

	red = (iter * 10) % 256;
	green = (iter * 5) % 256;
	blue = (iter * 15) % 256;
	return ((red << 16) + (green << 8) + blue);
}

int	julia(t_cmplx cnst, t_cmplx julia_c)
{
	int		iter;
	double	a;
	double	b;

	iter = 0;
	while (iter < MAX_ITER)
	{
		a = cnst.real * cnst.real;
		b = cnst.imag * cnst.imag;
		if (a + b > 4)
			return (iter * 0.3);
		cnst.imag = 2 * cnst.real * cnst.imag - julia_c.imag;
		cnst.real = a - b + julia_c.real;
		iter++;
	}
	return (0);
}

int	ft_fractol(t_cmplx cnst, t_cmplx julia_c, t_mlx mlx)
{
	t_cmplx	z;
	int		iter;
	double	a;
	double	b;

	z.real = 0;
	z.imag = 0;
	iter = 0;
	while (iter++ < MAX_ITER)
	{
		a = z.real * z.real;
		b = z.imag * z.imag;
		if (a + b > 4)
			return (color_changer(iter * 0.7) + mlx.col);
		if (!ft_strcmp(mlx.av[1], "ship"))
			z.imag = ft_abs(2 * z.real * z.imag) + cnst.imag;
		else if (!ft_strcmp(mlx.av[1], "julia"))
			return (color_changer(julia(cnst, julia_c)) + mlx.col);
		else
			z.imag = 2 * z.imag * z.real + cnst.imag;
		z.real = a - b + cnst.real;
	}
	return (color_changer(0));
}

void	main_drawer(t_mlx mlx)
{
	int			y;
	int			x;
	int			color;
	t_cmplx		cnst;
	t_cmplx		julia_c;

	if (mlx.ac > 2)
	{
		julia_c.real = ft_atof(mlx.av[2]);
		julia_c.imag = ft_atof(mlx.av[3]);
	}
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			cnst.real = (x - WIDTH / 2.0) * 4.0 / WIDTH * mlx.zoom + mlx.r_l;
			cnst.imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT * mlx.zoom + mlx.u_d;
			color = ft_fractol(cnst, julia_c, mlx);
			my_mlx_pixel_put(mlx.image, x, y, color);
		}
	}
	mlx_put_image_to_window(mlx.unit, mlx.window, mlx.image->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_data	tmp;

	mlx.image = &tmp;
	mlx.av = av;
	mlx.zoom = 1.0;
	mlx.col = 1.0;
	mlx.ac = ac;
	name_check(ac, av);
	mlx.unit = mlx_init();
	fail_handling(mlx.unit);
	mlx.window = mlx_new_window(mlx.unit, WIDTH, HEIGHT, "Fract-ol");
	fail_handling(mlx.window);
	mlx.image->img = mlx_new_image(mlx.unit, WIDTH, HEIGHT);
	fail_handling(mlx.image->img);
	mlx.image->img_addr = mlx_get_data_addr(mlx.image->img,
			&mlx.image->bits_per_pixel,
			&mlx.image->size_line, &mlx.image->endian);
	(fail_handling(mlx.image->img_addr), main_drawer(mlx));
	mlx_mouse_hook(mlx.window, zooming, &mlx);
	mlx_key_hook(mlx.window, handle_key, &mlx);
	mlx_hook(mlx.window, 17, 0, close_window, &mlx);
	mlx_loop(mlx.unit);
	return (0);
}
