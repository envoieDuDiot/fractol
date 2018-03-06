/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:12:22 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/06 16:12:23 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	keycode3(int k, t_param *p)
{
	if (k == THREE)
	{
		p->r += 231;
		p->g += 231;
		p->b += 231;
		p->r2 += 231;
		p->g2 += 231;
		p->b2 += 231;
	}
}

void	keycode2(int k, t_param *p)
{
	if (k == ZERO)
	{
		p->r += 321;
		p->g += 321;
		p->b += 321;
	}
	if (k == ONE)
	{
		p->r2 += 234;
		p->g2 += 234;
		p->b2 += 234;
	}
	if (k == TWO)
	{
		p->r2 -= 234;
		p->g2 -= 234;
		p->b2 -= 234;
	}
}

int		keycode(int k, t_param *p)
{
	if (k == ESC)
		exit(0);
	if (k == UP)
		p->zoom_y -= 20;
	if (k == DOWN)
		p->zoom_y += 20;
	if (k == LEFT)
		p->zoom_x -= 20;
	if (k == RIGHT)
		p->zoom_x += 20;
	if (k == PLUS && p->zoom > 0.000001)
		p->zoom -= 0.2 * p->zoom;
	if (k == MINUS && p->zoom < 0.2)
		p->zoom += 0.05 * p->zoom;
	if (k == MULT)
		p->iter_max += 2;
	if (k == DIV && p->iter_max > 10)
		p->iter_max -= 2;
	keycode2(k, p);
	keycode3(k, p);
	launcher(p);
	return (0);
}
