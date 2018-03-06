/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:32:35 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/06 16:40:10 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mouse_move(int x, int y, t_param *p)
{
	p->c_r = (double)(x - WH / 2) / 500;
	p->c_i = (double)(y - HT / 2) / 500;
	launcher(p);
	return (0);
}

void	scroll_zoom_in(int x, int y, t_param *p)
{
	if (x > WH / 2 && y > HT / 2 && p->zoom > 0.001)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y -= (y - HT / 2);
		p->zoom_x -= (x - WH / 2);
	}
	if (x < WH / 2 && y > HT / 2 && p->zoom > 0.001)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y -= (y - HT / 2);
		p->zoom_x += (x - WH / 2);
	}
	if (x < WH / 2 && y < HT / 2 && p->zoom > 0.001)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y -= (y - HT / 2);
		p->zoom_x -= (x - WH / 2);
	}
	if (x > WH / 2 && y < HT / 2 && p->zoom > 0.001)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y += (y - HT / 2);
		p->zoom_x -= (x - WH / 2);
	}
	scroll_zoom_in2(x, y, p);
}

void	scroll_zoom_in2(int x, int y, t_param *p)
{
	if (x > WH / 2 && y > HT / 2 && p->zoom < 0.001)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y -= 2 * (y - HT / 2);
		p->zoom_x -= 2 * (x - WH / 2);
	}
	if (x < WH / 2 && y > HT / 2 && p->zoom < 0.001)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y -= 1.2 * (y - HT / 2);
		p->zoom_x += 1.2 * (x - WH / 2);
	}
	if (x < WH / 2 && y < HT / 2 && p->zoom < 0.001)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y -= 1.2 * (y - HT / 2);
		p->zoom_x -= 1.2 * (x - WH / 2);
	}
	if (x > WH / 2 && y < HT / 2 && p->zoom < 0.001)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y += 1.2 * (y - HT / 2);
		p->zoom_x -= 1.2 * (x - WH / 2);
	}
}

void	scroll_zoom_out(int x, int y, t_param *p)
{
	if (x > WH / 2 && y > HT / 2)
	{
		p->zoom += 0.2 * p->zoom;
		p->zoom_y -= (y - HT / 2);
		p->zoom_x -= (x - WH / 2);
	}
	if (x < WH / 2 && y > HT / 2)
	{
		p->zoom += 0.2 * p->zoom;
		p->zoom_y -= (y - HT / 2);
		p->zoom_x += (x - WH / 2);
	}
	if (x < WH / 2 && y < HT / 2)
	{
		p->zoom += 0.2 * p->zoom;
		p->zoom_y -= (y - HT / 2);
		p->zoom_x -= (x - WH / 2);
	}
	if (x > WH / 2 && y < HT / 2)
	{
		p->zoom += 0.2 * p->zoom;
		p->zoom_y += (y - HT / 2);
		p->zoom_x -= (x - WH / 2);
	}
}

int		mouse_scroll(int k, int x, int y, t_param *p)
{
	if (k == 1 && p->fra <= 4)
		p->fra += 1;
	if (k == 2 && p->fra >= 2)
	p->fra -= 1;
	if (k == 4 && p->zoom > 0.000001)
		scroll_zoom_in(x, y, p);
	if (k == 5 && p->zoom < 0.2)
		scroll_zoom_out(x, y, p);
	launcher(p);
	return (0);
}
