#include "../include/fractol.h"

void	init_mandelbrot(t_param *p)
{
	p->zoom = 0.005;
	p->iter_max = 70;
	p->zoom_x = WH / 2;
	p->zoom_y = HT / 2;
	p->on = 1;
}

int		rgb(char r, char g, char b)
{
	return ((r & 0xFF << 16) + (g & 0xFF << 8) + (b & 0xff));
}

void	pixel_put(t_param *p, int color)
{
	char	*color_data;

	color_data = mlx_get_data_addr(p->img, &p->bpp, &p->sz_ln, &p->endian);
	color_data += p->y * p->sz_ln;
	color_data += p->x * p->bpp / 8;
	color_data[0] = color;
	color_data[1] = color >> 8;
	color_data[2] = color >> 16;
}

void	calculate_mandelbrot(t_param *p)
{
	int		i;
	double		tmp;

	i = 0;
	p->c_r = (p->x - p->zoom_x) * p->zoom;
	p->c_i = (p->y - p->zoom_y) * p->zoom;
	p->z_r = 0;
	p->z_i = 0;
	while (p->z_r * p->z_r + p->z_i * p->z_i <= 4 && i < p->iter_max)
	{
		tmp = p->z_r;
		p->z_r = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r;
		p->z_i = 2 * p->z_i * tmp + p->c_i;
		i++;
	}
	if (i == p->iter_max)
		pixel_put(p, rgb((char)0, (char)0, (char)(255 / i) * i));
	else
		pixel_put(p, 0);
}

void	mandelbrot(t_param *p)
{
	if (p->on == 0)
		init_mandelbrot(p);
	p->y = 0;
	while (p->y < HT)
	{
		p->x = 0;
		while (p->x < WH)
		{
			calculate_mandelbrot(p);
			p->x++;
		}
		p->y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	usage(void)
{
	ft_putendl("usage: Mandelbrot: ./fractol [-m, -M, -mandelbrot]\n       Julia:      ./fractol [-j, -J, -julia]");
	exit(0);
}

void	which_fractal(t_param *p)
{
	if (p->ac < 2 || p->ac > 2)
		usage();
	if (ft_strcmp(p->argv,"-m") == 0 || ft_strcmp(p->argv, "-M") == 0
			|| ft_strcmp(p->argv, "-mandelbrot") == 0)
		p->fra = 1;
	else if (ft_strcmp(p->argv, "-j") == 0 || ft_strcmp(p->argv, "-J") == 0
			|| ft_strcmp(p->argv, "-julia") == 0)
		p->fra = 2;
	else
		usage();
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
	launcher(p);
	return (0);
}

void	mlx_stuff(t_param *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WH, HT, "Fractol");
	p->img = mlx_new_image(p->mlx, WH, HT);
	mlx_hook(p->win, 2, 0, keycode, p);
}



void	launcher(t_param *p)
{
	if (p->fra == 1)
		mandelbrot(p);
//	if (p->fra == 2)
//		julia(p);
}

int		main(int ac, char **av)
{
	t_param		*p;

	if (!(p = malloc(sizeof(t_param))))
		return (EXIT_FAILURE);
	p->argv = av[1];
	p->ac = ac;
	which_fractal(p);
	mlx_stuff(p);
	init_mandelbrot(p);
	launcher(p);
	mandelbrot(p);
	mlx_loop(p->mlx);
	return (0);
}
