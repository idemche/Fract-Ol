/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 22:08:36 by idemchen          #+#    #+#             */
/*   Updated: 2017/04/02 01:30:28 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_shifts(int keycode, t_basis *fractol)
{
	if (keycode == 124)
	{
		BORDERS.max_x += 0.01;
		BORDERS.min_x += 0.01;
	}
	if (keycode == 123)
	{
		BORDERS.max_x -= 0.01;
		BORDERS.min_x -= 0.01;
	}
	if (keycode == 125)
	{
		BORDERS.max_y += 0.01;
		BORDERS.min_y += 0.01;
	}
	if (keycode == 126)
	{
		BORDERS.max_y -= 0.01;
		BORDERS.min_y -= 0.01;
	}
	ft_screen_init(fractol);
}

int		ft_refresh(int keycode, t_basis *fractol)
{
	(keycode == 53) ? exit(1) : 0;
	(keycode == 69) ? (fractol->depth += 10) && ft_screen_init(fractol) : 0;
	(keycode == 78) ? (fractol->depth -= 10) && ft_screen_init(fractol) : 0;
	(keycode == 49) ? ft_fractol_initializer(fractol)
					&& ft_screen_init(fractol) : 0;
	if (keycode == 13)
		fractol->flag = 2;
	if (keycode == 14)
		fractol->flag = 0;
	if (keycode == 1)
		fractol->flag = 1;
	if (keycode == 116)
		ft_zoom(4, SIZE_X / 2, SIZE_Y / 2, fractol);
	if (keycode == 121)
		ft_zoom(5, SIZE_X / 2, SIZE_Y / 2, fractol);
	if (keycode == 124 || keycode == 123
		|| keycode == 125 || keycode == 126)
		ft_shifts(keycode, fractol);
	return (1);
}

int		ft_mouse_refresh(int keycode, int x, int y, t_basis *fractol)
{
	(keycode == 5 || keycode == 4) ? ft_zoom(keycode, x, y, fractol) : 0;
	(keycode == 1) ? fractol->julia = 0 : 0;
	if (fractol->julia == 0)
		fractol->julia = (keycode == 2) ? 1 : 0;
	return (1);
}

int		ft_julia_mouse_init(int x, int y, t_basis *fractol)
{
	(fractol->julia && (fractol->fract == 3 || fractol->fract == 5)) ?
		ft_real_calculation(&PIXEL.j_real, fractol, x) &&
		ft_imaginary_calculation(&PIXEL.j_imag, fractol, y) &&
		ft_screen_init(fractol) : 0;
	return (1);
}

int		ft_destroy(void)
{
	exit(1);
}
