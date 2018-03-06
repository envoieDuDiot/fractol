/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:12:42 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/06 16:12:44 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		main(int ac, char **av)
{
	t_param		*p;

	if (!(p = malloc(sizeof(t_param))))
		return (EXIT_FAILURE);
	init_param(p);
	p->argv = av[1];
	p->ac = ac;
	which_fractal(p);
	mlx_stuff(p);
	init(p);
	launcher(p);
	mlx_loop(p->mlx);
	return (0);
}
