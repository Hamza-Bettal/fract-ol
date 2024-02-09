/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:35:01 by hbettal           #+#    #+#             */
/*   Updated: 2024/02/08 19:26:22 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# define MAX_ITER 150
# define WIDTH 800
# define HEIGHT 800

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
}				t_data;

typedef struct s_mlx
{
	void	*unit;
	void	*window;
	t_data	*image;
	char	**av;
	int		ac;
	double	zoom;
	double	r_l;
	double	u_d;
	int		col;
}	t_mlx;

typedef struct s_cmplx
{
	double	real;
	double	imag;
}	t_cmplx;

void	main_drawer(t_mlx mlx);
int		ft_atoi_check(char *str);
int		ft_strcmp(char *s1, char *s2);
int		name_check(int ac, char **av);
double	ft_atof(char *str);
int		zooming(int botton, int x, int y, t_mlx *mlx);
int		handle_key(int botton, t_mlx *mlx);
int		close_window(t_mlx *mlx);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	fail_handling(void *ptr);
double	ft_abs(double num);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif