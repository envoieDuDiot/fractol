/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:41:44 by vvinogra          #+#    #+#             */
/*   Updated: 2017/12/31 15:33:29 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_1(t_frac *frac)
{
	frac->rgb->r = frac->i * 15;
	frac->rgb->g = frac->i * 10;
	frac->rgb->b = frac->i;
}

void	color_2(t_frac *frac)
{
	frac->rgb->r = frac->i;
	frac->rgb->g = frac->i * 10;
	frac->rgb->b = frac->i * 15;
}

void	color_3(t_frac *frac)
{
	frac->rgb->r = frac->i * 17;
	frac->rgb->g = frac->i * 9;
	frac->rgb->b = frac->i * 19;
}

void	color_4(t_frac *frac)
{
	frac->rgb->r = frac->i;
	frac->rgb->g = frac->i * 14;
	frac->rgb->b = frac->i * 4;
}

void	color(int keycode, t_frac *frac)
{
	if (keycode == 18)
		frac->color_nb = 1;
	if (keycode == 19)
		frac->color_nb = 2;
	if (keycode == 20)
		frac->color_nb = 3;
	if (keycode == 21)
		frac->color_nb = 4;
	if (keycode == 23)
		frac->color_nb = 5;
	if (keycode == 22)
		frac->color_nb = 6;
	if (keycode == 26)
		frac->color_nb = 7;
	if (keycode == 28)
		frac->color_nb = 8;
	if (keycode == 25)
		frac->color_nb = 9;
}
