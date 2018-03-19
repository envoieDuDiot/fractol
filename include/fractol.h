/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:53:27 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/14 04:08:14 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdarg.h>
# include <limits.h>
# include <wchar.h>

# define HT 800
# define WH 800

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 69
# define MINUS 78
# define MULT 67
# define DIV 75
# define ZERO 82
# define ONE 83
# define TWO 84
# define THREE 85

typedef struct	s_param
{
	int			x;
	int			y;

	double		q;
	double		d;
	int			r;
	int			r2;
	int			g;
	int			g2;
	int			b;
	int			b2;
	double		zoom;
	int			iter_max;
	double		zoom_x;
	double		zoom_y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;

	int			fra;

	int			ac;
	char		*argv;

	void		*mlx;
	void		*win;
	int			wh;
	int			ht;
	void		*img;
	int			bpp;
	int			sz_ln;
	int			endian;
}				t_param;

void			calculate_ft_random_fabs(t_param *p);
void			ft_random_fabs(t_param *p);
void			calculate_mandelbrot(t_param *p);
void			mandelbrot(t_param *p);
void			calculate_mandelbrot_v2(t_param *p);
void			calculate_burningship(t_param *p);
void			burningship(t_param *p);
void			mandelbrot_v2(t_param *p);
void			init(t_param *p);
int				rgb(char r, char g, char b);
void			pixel_put(t_param *p, int color);
void			mlx_stuff(t_param *p);
void			calculate_ft_random_tan(t_param *p);
void			ft_random_tan(t_param *p);
void			usage(void);
void			which_fractal(t_param *p);
void			launcher(t_param *p);
void			calculate_julia(t_param *p);
void			julia(t_param *p);
void			init_param(t_param *p);
void			init_param2(t_param *p);
int				keycode(int k, t_param *p);
void			keycode2(int k, t_param *p);
void			keycode3(int k, t_param *p);
int				mouse_move(int x, int y, t_param *p);
void			scroll_zoom_in(int x, int y, t_param *p);
void			scroll_zoom_in2(int x, int y, t_param *p);
void			scroll_zoom_out(int x, int y, t_param *p);
int				mouse_scroll(int k, int x, int y, t_param *p);
void			user_guide(void);

#endif
