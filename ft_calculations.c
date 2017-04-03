/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:57:51 by idemchen          #+#    #+#             */
/*   Updated: 2017/04/02 01:32:12 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_real_calculation(double *real, t_basis *fractol, double x)
{
	*real = ((fractol->borders.max_x
		- fractol->borders.min_x) / SIZE_X) * x
	+ fractol->borders.min_x;
	return (1);
}

int		ft_imaginary_calculation(double *img, t_basis *fractol, double y)
{
	*img = ((fractol->borders.max_y
		- fractol->borders.min_y) / SIZE_Y) * y
	+ fractol->borders.min_y;
	return (1);
}

void	ft_rgb_init(t_basis *fractol, int rgb)
{
	PIXEL.green = (rgb >> 8) -
	((PIXEL.red = (rgb >> 16)) << 8);
	PIXEL.blue = rgb - (PIXEL.red << 16) - (PIXEL.green << 8);
}

int		ft_zoom(int keycode, int x, int y, t_basis *fractol)
{
	double real;
	double image;
	double multiplicator;

	ft_real_calculation(&real, fractol, x);
	ft_imaginary_calculation(&image, fractol, y);
	multiplicator = (keycode == 4) ? 0.9 : 1.1;
	BORDERS.max_x = BORDERS.max_x * multiplicator + real * (1 - multiplicator);
	BORDERS.min_x = BORDERS.min_x * multiplicator + real * (1 - multiplicator);
	BORDERS.max_y = BORDERS.max_y * multiplicator + image * (1 - multiplicator);
	BORDERS.min_y = BORDERS.min_y * multiplicator + image * (1 - multiplicator);
	return (ft_screen_init(fractol));
}

int		ft_random_color(int keycode, t_basis *fractol)
{
	if (keycode == 12)
	{
		fractol->color_shift =
		((int)time(NULL) % 100) * (time(NULL) % 300) * (0xFF0000 % 200);
		ft_screen_init(fractol);
	}
	return (1);
}
