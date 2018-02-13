/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_comparing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:30:23 by vvinogra          #+#    #+#             */
/*   Updated: 2018/01/02 14:14:17 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_frac(t_frac *frac)
{
	if (frac->nb == 1)
		ft_draw_man(frac);
	if (frac->nb == 2)
		ft_draw_jul(frac);
	if (frac->nb == 3)
		ft_draw_b(frac);
	if (frac->nb == 4)
		ft_draw_p(frac);
	if (frac->nb == 5)
		ft_draw_t(frac);
	if (frac->nb == 6)
		ft_draw_jul_s(frac);
	if (frac->nb == 7)
		ft_draw_my(frac);
	if (frac->nb == 8)
		ft_draw_c(frac);
}

void	comparing(char **argv, int i, t_frac *frac)
{
	if (ft_strcmp(argv[i], "-m") == 0)
	{
		frac->nb = 1;
		solution_m(frac);
	}
	if (ft_strcmp(argv[i], "-j") == 0)
	{
		frac->nb = 2;
		solution_j(frac);
	}
	if (ft_strcmp(argv[i], "-b") == 0)
	{
		frac->nb = 3;
		solution_b(frac);
	}
	if (ft_strcmp(argv[i], "-p") == 0)
	{
		frac->nb = 4;
		solution_p(frac);
	}
	if (ft_strcmp(argv[i], "-t") == 0)
	{
		frac->nb = 5;
		solution_t(frac);
	}
}

void	comparing2(char **argv, int i, t_frac *frac)
{
	if (ft_strcmp(argv[i], "-j_s") == 0)
	{
		frac->nb = 6;
		solution_j(frac);
	}
	if (ft_strcmp(argv[i], "-my") == 0)
	{
		frac->nb = 7;
		solution_my(frac);
	}
	if (ft_strcmp(argv[i], "-c") == 0)
	{
		frac->nb = 8;
		solution_c(frac);
	}
}
