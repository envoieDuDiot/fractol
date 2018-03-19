/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:12:51 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/14 04:07:35 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calculate_burningship(t_param *p)
{
	int		i;
	double	tmp;

	i = 0;
	p->c_r = (p->x - p->zoom_x) * p->zoom;
	p->c_i = (p->y - p->zoom_y) * p->zoom;
	p->z_r = 0;
	p->z_i = 0;
	while (p->z_r * p->z_r + p->z_i * p->z_i <= 4 && i < p->iter_max)
	{
		tmp = p->z_r;
		p->z_r = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r;
		p->z_i = fabs(2 * p->z_i * tmp + p->c_i);
		i++;
	}
	if (i == p->iter_max)
		pixel_put(p, rgb((char)p->r, (char)p->g, (char)((p->b * i)
		/ p->iter_max)));
	else
		pixel_put(p, rgb((char)((i * p->r2) / p->iter_max), (char)((i * p->g2)
		/ p->iter_max), (char)((i * p->b2) / p->iter_max)));
}

void	burningship(t_param *p)
{
	p->y = 0;
	while (p->y < HT)
	{
		p->x = 0;
		while (p->x < WH)
		{
			calculate_burningship(p);
			p->x++;
		}
		p->y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
