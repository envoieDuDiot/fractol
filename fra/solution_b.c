/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:38:29 by vvinogra          #+#    #+#             */
/*   Updated: 2017/12/30 22:12:38 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_b(t_frac *frac)
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
		y_t = fabs(2 * x_t * y_t) + frac->c_im;
		x_t = tem;
		frac->i++;
	}
	if (frac->i < frac->max_iter)
		pixel_image_put(frac);
}

void	ft_draw_b(t_frac *frac)
{
	frac->y = 0;
	while (frac->y < WIN_HEIGHT)
	{
		frac->x = 0;
		frac->c_im = (frac->y - WIN_HEIGHT / 2) /
			(0.25 * frac->zoom * WIN_HEIGHT) + frac->y_move;
		while (frac->x < WIN_WIDTH)
		{
			calculate_b(frac);
			frac->x++;
		}
		frac->y++;
	}
}

void	solution_b(t_frac *frac)
{
	ft_draw_b(frac);
	mlx_hook(frac->win, 2, 5, key_func, frac);
	mlx_mouse_hook(frac->win, mouse_func, frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->im->image, 0, 0);
}
