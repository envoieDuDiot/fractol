/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:13:07 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/14 04:07:47 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	usage(void)
{
	ft_putendl("usage: how to use:         ./fractol [-info]");
	ft_putendl("       Mandelbrot:         ./fractol [-m, -M, -mandelbrot]");
	ft_putendl("       Julia:              ./fractol [-j, -J, -julia]");
	ft_putendl("       Tangente            ./fractol [-t, -T, -tangente]");
	ft_putendl("       Absolue:            ./fractol [-a, -A, -absolue]");
	ft_putstr("       Mandelbrot V2:      ");
	ft_putendl("./fractol [-mv2, -MV2, -mandelbrot v2]");
	ft_putendl("       Burningship:         ./fractol [-b, -B, -burningship]");
	exit(0);
}

void	user_guide(void)
{
	ft_putendl("\t\t__________________________");
	ft_putendl("\t\t|                        |");
	ft_putendl("\t\t|-------USER GUIDE-------|");
	ft_putendl("\t\t|                        |");
	ft_putendl("\t\t|    ESC    :   quit     |");
	ft_putendl("\t\t|  ARROWS   :  MOVING    |");
	ft_putendl("\t\t|   0,1,2   :  COLOR     |");
	ft_putendl("\t\t|    +,-    :  ZOOM      |");
	ft_putendl("\t\t|   SCROLL  :  ZOOM      |");
	ft_putendl("\t\t|    /,*    :  ITERATION |");
	ft_putendl("\t\t| LFT CLIK  :  NEXT      |");
	ft_putendl("\t\t| RGT CLIK  :  PREVIOUS  |");
	ft_putendl("\t\t|                        |");
	ft_putendl("\t\t|________________________|");
	exit(0);
}

void	which_fractal(t_param *p)
{
	if (p->ac < 2 || p->ac > 2)
		usage();
	if (ft_strcmp(p->argv, "-m") == 0 || ft_strcmp(p->argv, "-M") == 0
			|| ft_strcmp(p->argv, "-mandelbrot") == 0)
		p->fra = 1;
	else if (ft_strcmp(p->argv, "-j") == 0 || ft_strcmp(p->argv, "-J") == 0
			|| ft_strcmp(p->argv, "-julia") == 0)
		p->fra = 2;
	else if (ft_strcmp(p->argv, "-t") == 0 || ft_strcmp(p->argv, "-T") == 0
			|| ft_strcmp(p->argv, "-tangente") == 0)
		p->fra = 3;
	else if (ft_strcmp(p->argv, "-a") == 0 || ft_strcmp(p->argv, "-A") == 0
			|| ft_strcmp(p->argv, "-absolue") == 0)
		p->fra = 4;
	else if (ft_strcmp(p->argv, "-mv2") == 0 || ft_strcmp(p->argv, "-MV2") == 0
			|| ft_strcmp(p->argv, "-mandelbrot v2") == 0)
		p->fra = 5;
	else if (ft_strcmp(p->argv, "-b") == 0 || ft_strcmp(p->argv, "-B") == 0
			|| ft_strcmp(p->argv, "-burningship") == 0)
		p->fra = 6;
	else if (ft_strcmp(p->argv, "-info") == 0)
		user_guide();
	else
		usage();
}

void	launcher(t_param *p)
{
	if (p->fra == 1)
		mandelbrot(p);
	if (p->fra == 2)
		julia(p);
	if (p->fra == 3)
		ft_random_tan(p);
	if (p->fra == 4)
		ft_random_fabs(p);
	if (p->fra == 5)
		mandelbrot_v2(p);
	if (p->fra == 6)
		burningship(p);
}
