/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 20:10:03 by vvinogra          #+#    #+#             */
/*   Updated: 2017/12/30 20:35:22 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_5(t_frac *frac)
{
	frac->rgb->r = frac->i * 24;
	frac->rgb->g = frac->i * 25;
	frac->rgb->b = frac->i * 4;
}

void	color_6(t_frac *frac)
{
	frac->rgb->r = frac->i * 12;
	frac->rgb->g = 0;
	frac->rgb->b = frac->i * 10;
}

void	color_7(t_frac *frac)
{
	frac->rgb->r = frac->i * 4;
	frac->rgb->g = frac->i * 25;
	frac->rgb->b = frac->i * 24;
}

void	color_8(t_frac *frac)
{
	frac->rgb->r = frac->i * 25;
	frac->rgb->g = frac->i * 12;
	frac->rgb->b = frac->i * 12;
}

void	color_9(t_frac *frac)
{
	frac->rgb->r = frac->i * 7;
	frac->rgb->g = frac->i * 4;
	frac->rgb->b = frac->i * 12;
}
