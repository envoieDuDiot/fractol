/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:12:57 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/14 03:18:45 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init(t_param *p)
{
	p->zoom = 0.005;
	p->iter_max = 150;
	p->zoom_x = WH / 2;
	p->zoom_y = HT / 2;
	p->c_r = 0.285;
	p->c_i = 0.01;
	p->r = 20;
	p->r2 = 0;
	p->g = 0;
	p->g2 = 0;
	p->b = 51;
	p->b2 = 255;
}

int		rgb(char r, char g, char b)
{
	return ((r & 0xFF << 16) + (g & 0xFF << 8) + (b & 0xff));
}

void	pixel_put(t_param *p, int color)
{
	char	*color_data;

	color_data = mlx_get_data_addr(p->img, &p->bpp, &p->sz_ln, &p->endian);
	color_data += p->y * p->sz_ln;
	color_data += p->x * p->bpp / 8;
	color_data[0] = color;
	color_data[1] = color >> 8;
	color_data[2] = color >> 16;
}

void	mlx_stuff(t_param *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WH, HT, "Fractol");
	p->img = mlx_new_image(p->mlx, WH, HT);
	mlx_string_put(p->mlx, p->win, 40, 22, 0xffffff, "hello essai");
	mlx_hook(p->win, 2, 0, keycode, p);
	mlx_hook(p->win, 6, 0, mouse_move, p);
	mlx_hook(p->win, 4, (1L << 2), &mouse_scroll, p);
}
