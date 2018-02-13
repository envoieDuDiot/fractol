/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:43:41 by vvinogra          #+#    #+#             */
/*   Updated: 2018/01/02 14:12:38 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include <mlx.h>
# include <math.h>
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

typedef struct	s_frac
{
	void			*mlx;
	void			*win;
	double			c_re;
	double			c_im;
	double			x;
	double			y;
	double			x_move;
	double			y_move;
	double			zoom;
	int				max_iter;
	struct s_image	*im;
	int				nb;
	int				i;
	struct s_rgb	*rgb;
	int				color_nb;
	int				stop;
	int				x_cur;
	int				y_cur;
}				t_frac;

typedef struct	s_rgb
{
	int r;
	int b;
	int g;
}				t_rgb;

typedef struct	s_image
{
	void		*image;
	char		*pic;
	int			bpp;
	int			stride;
	int			endian;
}				t_image;

void			pixel_image_put(t_frac *frac);
t_image			*create_new_im(void *mlx);
void			image_clear(t_image *im);

void			solution_m(t_frac *frac);
void			ft_draw_man(t_frac *frac);

void			solution_j_s(t_frac *frac);
void			ft_draw_jul_s(t_frac *frac);

void			solution_j(t_frac *frac);
void			ft_draw_jul(t_frac *frac);
int				mouse_julia(int x, int y, t_frac *frac);

void			solution_b(t_frac *frac);
void			ft_draw_b(t_frac *frac);

void			ft_draw_p(t_frac *frac);
void			solution_p(t_frac *frac);

void			solution_t(t_frac *frac);
void			ft_draw_t(t_frac *frac);

void			solution_my(t_frac *frac);
void			ft_draw_my(t_frac *frac);

void			solution_c(t_frac *frac);
void			ft_draw_c(t_frac *frac);

void			zoom_and_iter_move(int keycode, t_frac *frac);

int				key_func(int keycode, t_frac *frac);
int				mouse_func(int button, int x, int y, t_frac *frac);

void			color(int keycode, t_frac *frac);
void			color_1(t_frac *frac);
void			color_2(t_frac *frac);
void			color_3(t_frac *frac);
void			color_4(t_frac *frac);
void			color_5(t_frac *frac);
void			color_6(t_frac *frac);
void			color_7(t_frac *frac);
void			color_8(t_frac *frac);
void			color_9(t_frac *frac);

void			choose_frac(t_frac *frac);
void			comparing(char **argv, int i, t_frac *frac);
void			comparing2(char **argv, int i, t_frac *frac);

#endif
