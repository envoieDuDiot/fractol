/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_j.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:54:16 by vvinogra          #+#    #+#             */
/*   Updated: 2017/12/31 15:12:02 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_jul(t_frac *frac)
{
	double	x_t;
	double	y_t;
	double	tem;

	x_t = (frac->x - WIN_WIDTH / 2)
		/ (0.25 * frac->zoom * WIN_WIDTH) + frac->x_move;
	y_t = (frac->y - WIN_HEIGHT / 2) /
			(0.25 * frac->zoom * WIN_HEIGHT) + frac->y_move;
	frac->i = 0;
	while (x_t * x_t + y_t * y_t <= 4 && frac->i < frac->max_iter)
	{
		tem = x_t * x_t - y_t * y_t + frac->c_re;
		y_t = 2 * x_t * y_t + frac->c_im;
		x_t = tem;
		frac->i++;
	}
	if (frac->i < frac->max_iter)
		pixel_image_put(frac);
}

void	ft_draw_jul(t_frac *frac)
{
	frac->y = 0;
	while (frac->y < WIN_HEIGHT)
	{
		frac->x = 0;
		while (frac->x < WIN_WIDTH)
		{
			calculate_jul(frac);
			frac->x++;
		}
		frac->y++;
	}
}

void	solution_j(t_frac *frac)
{
	ft_draw_jul(frac);
	mlx_hook(frac->win, 2, 5, key_func, frac);
	mlx_hook(frac->win, 6, 1L < 6, mouse_julia, frac);
	mlx_mouse_hook(frac->win, mouse_func, frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->im->image, 0, 0);
}
