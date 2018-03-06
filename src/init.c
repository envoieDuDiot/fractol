/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:12:30 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/06 16:22:28 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_param(t_param *p)
{
	p->x = 0;
	p->y = 0;
	p->q = 0;
	p->d = 0;
	p->r = 0;
	p->r2 = 0;
	p->g = 0;
	p->g2 = 0;
	p->b = 0;
	p->b2 = 0;
	p->zoom = 0;
	p->iter_max = 0;
	p->zoom_x = 0;
	p->zoom_y = 0;
	init_param2(p);
}

void	init_param2(t_param *p)
{
	p->c_r = 0;
	p->c_i = 0;
	p->z_r = 0;
	p->z_i = 0;
	p->fra = 0;
	p->ac = 0;
	p->argv = NULL;
	p->mlx = NULL;
	p->win = NULL;
	p->wh = 0;
	p->ht = 0;
	p->img = NULL;
	p->bpp = 0;
	p->sz_ln = 0;
	p->endian = 0;
}
