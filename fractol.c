/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 18:48:44 by idemchen          #+#    #+#             */
/*   Updated: 2017/04/02 01:31:04 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_image_creation(t_basis *fractol)
{
	IMAGE.length = 0;
	IMAGE.bits = 0;
	IMAGE.end = 0;
	IMAGE.image = mlx_new_image(fractol->mlx, SIZE_X, SIZE_Y);
	IMAGE.line = mlx_get_data_addr(IMAGE.image,
		&IMAGE.bits, &IMAGE.length, &IMAGE.end);
}

void	ft_draw_fractol(t_basis *fractol, int x, int y)
{
	int coord;

	coord = y * IMAGE.length + (x << 2);
	if (x < SIZE_Y * SIZE_X * 4)
	{
		IMAGE.line[coord] = PIXEL.blue;
		IMAGE.line[coord + 1] = PIXEL.green;
		IMAGE.line[coord + 2] = PIXEL.red;
	}
}

int		ft_screen_init(t_basis *fractol)
{
	int x;
	int y;
	int value;

	x = -1;
	value = 0;
	ft_image_creation(fractol);
	while ((y = -1) && (++x < SIZE_X)
		&& ft_real_calculation(&PIXEL.real, fractol, x))
		while (++y < SIZE_Y
			&& ft_imaginary_calculation(&PIXEL.imag, fractol, y))
		{
			ft_main_algorithm(fractol, &value);
			(value < fractol->depth) ?
			ft_rgb_init(fractol, value * fractol->color_shift)
			: ft_rgb_init(fractol, 0x000000);
			ft_draw_fractol(fractol, x, y);
		}
	mlx_put_image_to_window(fractol->mlx, fractol->window, IMAGE.image, 0, 0);
	free(IMAGE.image);
	return (1);
}

void	ft_mlx_init(t_basis *fractol)
{
	fractol->window =
	mlx_new_window((fractol->mlx = mlx_init()), SIZE_X, SIZE_Y, "42");
}

int		main(int argc, char const *argv[])
{
	t_basis fractol;

	if (argc < 2)
		return (write(1, "Right usage: ./fractol [num]\n", 29));
	ft_fract_check(&fractol, (char**)argv);
	ft_mlx_init(&fractol);
	ft_fractol_initializer(&fractol);
	fractol.color_shift = 0x0F0F0F;
	fractol.flag = 0;
	fractol.depth = 50;
	ft_mlx_usage(&fractol);
	return (0);
}
