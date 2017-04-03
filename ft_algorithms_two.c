/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 01:24:42 by idemchen          #+#    #+#             */
/*   Updated: 2017/04/02 01:25:22 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_matrix_algorithm(t_basis *fractol, int *value)
{
	double rz;
	double iz;
	double temp;

	*value = -1;
	rz = 0;
	iz = rz;
	while (++(*value) < fractol->depth)
	{
		temp = (PW(rz) - PW(iz));
		iz = 2 * (rz * iz) + sin(PIXEL.imag);
		rz = temp + cos(PIXEL.real);
		if ((PW(rz) + PW(iz)) > 4)
			break ;
	}
}

void	ft_julia_algorithm(t_basis *fractol, int *value)
{
	double rz;
	double iz;
	double temp;

	*value = -1;
	rz = PIXEL.real;
	iz = PIXEL.imag;
	while (++(*value) < fractol->depth)
	{
		temp = ((PW(rz) - PW(iz)));
		iz = 2 * rz * iz + PIXEL.j_imag;
		rz = temp + PIXEL.j_real;
		if ((PW(rz) + PW(iz)) > 4)
			break ;
	}
}

void	ft_kaleidoscope_algorithm(t_basis *fractol, int *value)
{
	double rz;
	double iz;
	double temp;

	*value = -1;
	rz = cos(PIXEL.real);
	iz = sin(PIXEL.imag);
	while (++(*value) < fractol->depth)
	{
		temp = ((PW(rz) - PW(iz)));
		iz = 2 * rz * iz + PIXEL.j_imag;
		rz = temp + PIXEL.j_real;
		if ((PW(rz) + PW(iz)) > 4)
			break ;
	}
}
