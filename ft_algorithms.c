/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:49:51 by idemchen          #+#    #+#             */
/*   Updated: 2017/04/02 05:46:21 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot_algorithm(t_basis *fractol, int *value)
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
		iz = 2 * rz * iz + PIXEL.imag;
		rz = temp + PIXEL.real;
		if ((PW(rz) + PW(iz)) > 4)
			break ;
	}
}

void	ft_burnship_algorithm(t_basis *fractol, int *value)
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
		iz = 2 * fabs(rz * iz) + (PIXEL.imag);
		rz = temp + (PIXEL.real);
		if ((PW(rz) + PW(iz)) > 4)
			break ;
	}
}

void	ft_fluger_algorithm(t_basis *fractol, int *value)
{
	double rz;
	double iz;
	double temp;

	*value = -1;
	rz = 0;
	iz = rz;
	while (++(*value) < fractol->depth)
	{
		temp = fabs(PW(rz) - PW(iz));
		iz = 2 * fabs(rz * iz) + (PIXEL.imag);
		rz = temp + (PIXEL.real);
		if ((PW(rz) + PW(iz)) > 4)
			break ;
	}
}

void	ft_island_algorithm(t_basis *fractol, int *value)
{
	double rz;
	double iz;
	double temp;

	*value = -1;
	rz = 0;
	iz = rz;
	while (++(*value) < fractol->depth)
	{
		temp = fabs(PW(rz) - PW(iz));
		iz = 2 * (rz * iz) + (PIXEL.imag);
		rz = temp + (PIXEL.real);
		if ((PW(rz) + PW(iz)) > 4)
			break ;
	}
}

void	ft_rooster_algorithm(t_basis *fractol, int *value)
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
		iz = fabs(2 * (rz * iz) + (PIXEL.imag));
		rz = temp + (PIXEL.real);
		if ((PW(rz) + PW(iz)) > 4)
			break ;
	}
}
