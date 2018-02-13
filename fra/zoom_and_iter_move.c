/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_and_iter_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 19:33:24 by vvinogra          #+#    #+#             */
/*   Updated: 2017/12/30 20:06:48 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_and_iter_move(int keycode, t_frac *frac)
{
	if (keycode == 69)
		frac->zoom *= 1.5;
	if (keycode == 78)
		frac->zoom /= 1.5;
	if (keycode == 75)
		frac->max_iter -= 10;
	if (keycode == 67)
		frac->max_iter += 10;
	if (keycode == 123)
		frac->x_move += 0.1 / frac->zoom;
	if (keycode == 124)
		frac->x_move += -0.1 / frac->zoom;
	if (keycode == 126)
		frac->y_move += 0.1 / frac->zoom;
	if (keycode == 125)
		frac->y_move += -0.1 / frac->zoom;
}
