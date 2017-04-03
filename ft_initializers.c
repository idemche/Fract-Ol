/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:41:32 by idemchen          #+#    #+#             */
/*   Updated: 2017/04/02 02:32:05 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_fract_check(t_basis *fractol, char **argv)
{
	if (argv[1][0] == '1')
		fractol->fract = 1;
	else if (argv[1][0] == '2')
		fractol->fract = 2;
	else if (argv[1][0] == '3')
		fractol->fract = 3;
	else if (argv[1][0] == '4')
		fractol->fract = 4;
	else if (argv[1][0] == '5')
		fractol->fract = 5;
	else if (argv[1][0] == '6')
		fractol->fract = 6;
	else if (argv[1][0] == '7')
		fractol->fract = 7;
	else if (argv[1][0] == '8')
		fractol->fract = 8;
	else
		exit(write(1,
		"Non-existing Fractol || try ./fractol [1 - 8]\n", 46));
}

int			ft_fractol_initializer(t_basis *fractol)
{
	fractol->borders.max_x = (fractol->fract != 1) ? 2.25 : 1;
	fractol->borders.max_y = (fractol->fract != 1) ? 2 : 1;
	fractol->borders.min_x = (fractol->fract != 1) ? -2.25 : -2;
	fractol->borders.min_y = (fractol->fract != 1) ? -2 : -1;
	return (1);
}

void		ft_main_algorithm(t_basis *fractol, int *value)
{
	if (fractol->fract == 1)
		ft_mandelbrot_algorithm(fractol, value);
	else if (fractol->fract == 2)
		ft_burnship_algorithm(fractol, value);
	else if (fractol->fract == 4)
		ft_matrix_algorithm(fractol, value);
	else if (fractol->fract == 5)
		ft_kaleidoscope_algorithm(fractol, value);
	else if (fractol->fract == 6)
		ft_fluger_algorithm(fractol, value);
	else if (fractol->fract == 7)
		ft_island_algorithm(fractol, value);
	else if (fractol->fract == 8)
		ft_rooster_algorithm(fractol, value);
	else if (fractol->fract == 3)
		ft_julia_algorithm(fractol, value);
}

int			ft_update(t_basis *fractol)
{
	if (fractol->flag == 1)
		ft_zoom(5, 400, 400, fractol);
	if (fractol->flag == 2)
		ft_zoom(4, 400, 400, fractol);
	return (1);
}

void		ft_mlx_usage(t_basis *fractol)
{
	ft_screen_init(fractol);
	mlx_key_hook(fractol->window, ft_refresh, fractol);
	mlx_mouse_hook(fractol->window, ft_mouse_refresh, fractol);
	mlx_hook(fractol->window, 6, 0, ft_julia_mouse_init, fractol);
	mlx_hook(fractol->window, 2, 5, ft_random_color, fractol);
	mlx_hook(fractol->window, 17, 0, ft_destroy, 0);
	mlx_loop_hook(fractol->mlx, ft_update, fractol);
	mlx_loop(fractol->mlx);
}
