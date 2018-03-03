#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
#include<stdarg.h>
#include <limits.h>
#include <wchar.h>

# define HT 680
# define WH 680

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

typedef struct	s_param
{
	int		x;
	int		y;

	double q;
	double d;
	int 	r;
	int		r2;
	int		g;
	int		g2;
	int		b;
	int		b2;
	double	zoom;
	int		iter_max;
	double	zoom_x;
	double	zoom_y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	int		fra;

	int		ac;
	char	*argv;

	void	*mlx;
	void	*win;
	int		wh;
	int		ht;
	void	*img;
	int		bpp;
	int		sz_ln;
	int		endian;
}				t_param;

void	launcher(t_param *p);
void	mlx_stuff(t_param *p);
int		keycode(int k, t_param *p);
void	which_fractal(t_param *p);
void	mandelbrot(t_param *p);
void	calculate_mandelbrot(t_param *p);
void	pixel_put(t_param *p, int color);
void	init_mandelbrot(t_param *p);

#endif
