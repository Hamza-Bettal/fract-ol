/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:39:49 by hbettal           #+#    #+#             */
/*   Updated: 2024/02/08 19:14:28 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *str)
{
	double	result;
	double	frac;
	int		i;
	int		sign;

	result = 0.0;
	frac = 0.1;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i++] == '.')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i++] - '0') * frac;
			frac /= 10.0;
		}
	}
	return (sign * result);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

int	correct_points(char *str, int i)
{
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && str[i + 1] == '.')
		{
			while (str[i + 2] >= '0' && str[i + 2] <= '9')
			{
				i++;
				if (!str[i + 2])
					return (0);
				else if (str[i + 2] <= '0' && str[i + 2] >= '9')
					return (1);
			}
			return (1);
		}
		else if ((str[i] >= '0' && str[i] <= '9') && !str[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] == '.' && !correct_points(str, i))
			return (0);
		i++;
	}
	return (1);
}

int	name_check(int ac, char **av)
{
	char	*str;

	str = "example : ./fractol mandelbrot\n or : ./fractol julia <r> <i>\n";
	if (ac > 1)
	{
		if (!ft_strcmp(av[1], "mandelbrot") && ac == 2)
			return (0);
		else if (!ft_strcmp(av[1], "julia") && ac == 4
			&& !ft_atoi_check(av[2]) && !ft_atoi_check(av[3]))
			return (0);
	}
	write(2, str, 62);
	exit(1);
}
