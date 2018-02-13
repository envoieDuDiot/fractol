/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 21:21:22 by vvinogra          #+#    #+#             */
/*   Updated: 2018/01/02 13:31:30 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_func(int button, int x, int y, t_frac *frac)
{
	image_clear(frac->im);
	if (button == 4)
	{
		frac->zoom *= 1.1;
		frac->y_move += (y - WIN_HEIGHT / 2) * 0.001 / frac->zoom;
		frac->x_move += (x - WIN_WIDTH / 2) * 0.001 / frac->zoom;
	}
	if (button == 5)
	{
		frac->y_move += (y - WIN_HEIGHT / 2) * 0.0001 / frac->zoom;
		frac->x_move += (x - WIN_WIDTH / 2) * 0.0001 / frac->zoom;
		frac->zoom /= 1.1;
	}
	choose_frac(frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->im->image, 0, 0);
	return (0);
}

int		mouse_julia(int x, int y, t_frac *frac)
{
	image_clear(frac->im);
	if (frac->stop == 0)
		frac->c_re = (x - WIN_WIDTH / 2)
			/ (0.25 * frac->zoom * WIN_WIDTH) + frac->x_move;
	if (frac->stop == 0)
		frac->c_im = (y - WIN_HEIGHT / 2)
			/ (0.25 * frac->zoom * WIN_HEIGHT) + frac->y_move;
	frac->x_cur = x;
	frac->y_cur = y;
	if (frac->nb == 2)
		ft_draw_jul(frac);
	if (frac->nb == 6)
		ft_draw_jul_s(frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->im->image, 0, 0);
	return (0);
}

void	helper(int keycode, t_frac *frac)
{
	if (keycode == 53)
	{
		mlx_destroy_window(frac->mlx, frac->win);
		exit(0);
	}
	if (keycode == 48 && frac->stop == 1)
	{
		frac->stop = 0;
		frac->c_im = (frac->y_cur - WIN_HEIGHT / 2)
			/ (0.25 * frac->zoom * WIN_HEIGHT) + frac->y_move;
		frac->c_re = (frac->x_cur - WIN_WIDTH / 2)
			/ (0.25 * frac->zoom * WIN_WIDTH) + frac->x_move;
	}
	else if (keycode == 48 && frac->stop == 0)
		frac->stop = 1;
}

int		key_func(int keycode, t_frac *frac)
{
	if (keycode == 82 || keycode == 29)
	{
		frac->max_iter = 30;
		frac->x_move = 0;
		frac->y_move = 0;
		frac->zoom = 1;
	}
	helper(keycode, frac);
	image_clear(frac->im);
	zoom_and_iter_move(keycode, frac);
	color(keycode, frac);
	choose_frac(frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->im->image, 0, 0);
	return (0);
}
