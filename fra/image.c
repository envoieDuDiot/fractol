/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:36:12 by vvinogra          #+#    #+#             */
/*   Updated: 2017/12/31 15:35:31 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_image_put(t_frac *frac)
{
	int j;

	if (frac->color_nb == 1)
		color_1(frac);
	if (frac->color_nb == 2)
		color_2(frac);
	if (frac->color_nb == 3)
		color_3(frac);
	if (frac->color_nb == 4)
		color_4(frac);
	if (frac->color_nb == 5)
		color_5(frac);
	if (frac->color_nb == 6)
		color_6(frac);
	if (frac->color_nb == 7)
		color_7(frac);
	if (frac->color_nb == 8)
		color_8(frac);
	if (frac->color_nb == 9)
		color_9(frac);
	j = 4 * (frac->y * WIN_WIDTH + frac->x);
	frac->im->pic[j] = frac->rgb->b;
	frac->im->pic[j + 1] = frac->rgb->g;
	frac->im->pic[j + 2] = frac->rgb->r;
}

t_image	*create_new_im(void *mlx)
{
	t_image *im;

	im = (t_image *)malloc(sizeof(t_image));
	im->image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	im->pic = mlx_get_data_addr(im->image, &im->bpp, &im->stride, &im->endian);
	im->bpp /= 8;
	return (im);
}

void	image_clear(t_image *im)
{
	ft_bzero(im->pic, WIN_WIDTH * WIN_HEIGHT * im->bpp);
}
