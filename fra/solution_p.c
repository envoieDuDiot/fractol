/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 22:15:27 by vvinogra          #+#    #+#             */
/*   Updated: 2017/12/31 15:36:44 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_p(t_frac *frac)
{
	double	x_t;
	double	y_t;
	double	tem;

	frac->c_re = (frac->x - WIN_WIDTH / 2)
		/ (0.25 * frac->zoom * WIN_WIDTH) + frac->x_move;
	x_t = 0;
	y_t = 0;
	frac->i = 0;
	while (x_t * x_t + y_t * y_t < 4 && frac->i < frac->max_iter)
	{
		tem = x_t * x_t - y_t * y_t + frac->c_re;
		y_t = x_t * y_t + frac->c_im;
		x_t = tem;
		frac->i++;
	}
	if (frac->i < frac->max_iter)
		pixel_image_put(frac);
}

void	ft_draw_p(t_frac *frac)
{
	frac->y = 0;
	while (frac->y < WIN_HEIGHT)
	{
		frac->x = 0;
		frac->c_im = (frac->y - WIN_HEIGHT / 2) /
			(0.25 * frac->zoom * WIN_HEIGHT) + frac->y_move;
		while (frac->x < WIN_WIDTH)
		{
			calculate_p(frac);
			frac->x++;
		}
		frac->y++;
	}
}

void	solution_p(t_frac *frac)
{
	ft_draw_p(frac);
	mlx_hook(frac->win, 2, 5, key_func, frac);
	mlx_mouse_hook(frac->win, mouse_func, frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->im->image, 0, 0);
}
