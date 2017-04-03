/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 18:46:17 by idemchen          #+#    #+#             */
/*   Updated: 2017/04/02 01:31:48 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <time.h>
# include <mlx.h>
# include <math.h>
# define SIZE_X 800
# define SIZE_Y 600
# define S(x)			#x
# define PW(x)			x * x
# define STR(a, b) 		a ## b
# define PIXEL			fractol->pixel
# define IMAGE			fractol->image
# define BORDERS		fractol->borders

typedef unsigned char	t_flag;
typedef struct			s_borders
{
	double max_x;
	double max_y;
	double min_x;
	double min_y;
}						t_borders;

typedef struct			s_pixel
{
	double	real;
	double	imag;
	double	j_real;
	double	j_imag;
	int		red;
	int		green;
	int		blue;
}						t_pixel;

typedef struct			s_image
{
	void	*image;
	int		length;
	int		bits;
	int		end;
	char	*line;
}						t_image;

typedef struct			s_basis
{
	void		*mlx;
	void		*window;
	int			rgb;
	int			color_shift;
	int			depth;
	t_flag		julia;
	t_flag		flag;
	t_borders	borders;
	t_pixel		pixel;
	t_image		image;
	int			fract;
}						t_basis;

void					ft_fract_check(t_basis *fractol, char **argv);
int						ft_fractol_initializer(t_basis *fractol);

int						ft_real_calculation(double *real,
	t_basis *fractol, double x);
int						ft_imaginary_calculation(double *img,
	t_basis *fractol, double y);
int						ft_screen_init(t_basis *fractol);
void					ft_main_algorithm(t_basis *fractol, int *value);
void					ft_rgb_init(t_basis *fractol, int rgb);

/*
**		ALGORITHMS
*/

void					ft_mandelbrot_algorithm(t_basis *fractol, int *value);
void					ft_burnship_algorithm(t_basis *fractol, int *value);
void					ft_matrix_algorithm(t_basis *fractol, int *value);
void					ft_julia_algorithm(t_basis *fractol, int *value);
void					ft_kaleidoscope_algorithm(t_basis *fractol, int *value);
int						ft_zoom(int keycode, int x, int y, t_basis *fractol);
void					ft_rooster_algorithm(t_basis *fractol, int *value);
void					ft_island_algorithm(t_basis *fractol, int *value);
void					ft_fluger_algorithm(t_basis *fractol, int *value);

/*
**		KEY_JUGGLING
*/

int						ft_update(t_basis *fractol);
int						ft_refresh(int keycode, t_basis *fractol);
int						ft_julia_mouse_init(int x, int y, t_basis *fractol);
int						ft_mouse_refresh(int keycode,
	int x, int y, t_basis *fractol);
int						ft_destroy(void);
void					ft_shifts(int keycode, t_basis *fractol);
int						ft_random_color(int keycode, t_basis *fractol);

void					ft_mlx_usage(t_basis *fractol);
#endif
