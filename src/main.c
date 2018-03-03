#include "../include/fractol.h"

void	init(t_param *p)
{
	p->zoom = 0.005;
	p->iter_max = 150;
	p->zoom_x = WH / 2;
	p->zoom_y = HT / 2;
	p->c_r = 0.285;
	p->c_i = 0.01;
	p->r = 20;
	p->r2 = 0;
	p->g = 0;
	p->g2 = 0;
	p->b = 51;
	p->b2 = 255;
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

void	calculate_mandelbrot_v2(t_param *p)
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
		p->z_i = tan(2 * p->z_i * tmp + p->c_i);
		i++;
	}
	if (i == p->iter_max)
		pixel_put(p, rgb((char)p->r, (char)p->g, (char)((p->b * i) / p->iter_max)));
	else
		pixel_put(p, rgb((char)((i * p->r2) / p->iter_max), (char)((i * p->g2) / p->iter_max), (char)((i * p->b2) / p->iter_max)));
}

void mandelbrot_v2(t_param *p)
{

	p->y = 0;
	while (p->y < HT)
	{
		p->x = 0;
		while (p->x < WH)
		{
			calculate_mandelbrot_v2(p);
			p->x++;
		}
		p->y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	calculate_ft_random_tan(t_param *p)
{
	int		i;

	i = 0;
	double	tmp;
	p->z_r = (p->x - p->zoom_x) * p->zoom;
	p->z_i = (p->y - p->zoom_y) * p->zoom;
	while (p->z_r * p->z_r + p->z_i * p->z_i <= 4 && i < p->iter_max)
	{
		tmp = p->z_r;
		p->z_r = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r;
		p->z_i = tan(2 * p->z_i * tmp + p->c_i);
		i++;
	}
	if (i == p->iter_max)
		pixel_put(p, rgb((char)p->r, (char)p->g, (char)((p->b * i) / p->iter_max)));
	else
		pixel_put(p, rgb((char)((i * p->r2) / p->iter_max), (char)((i * p->g2) / p->iter_max), (char)((i * p->b2) / p->iter_max)));
}

void ft_random_tan(t_param *p)
{

	p->y = 0;
	while (p->y < HT)
	{
		p->x = 0;
		while (p->x < WH)
		{
			calculate_ft_random_tan(p);
			p->x++;
		}
		p->y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	calculate_ft_random_fabs(t_param *p)
{
	int		i;

	i = 0;
	double	tmp;
	p->z_r = (p->x - p->zoom_x) * p->zoom;
	p->z_i = (p->y - p->zoom_y) * p->zoom;
	while (p->z_r * p->z_r + p->z_i * p->z_i <= 4 && i < p->iter_max)
	{
		tmp = p->z_r;
		p->z_r = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r;
		p->z_i = fabs(2 * p->z_i * tmp + p->c_i);
		i++;
	}
	if (i == p->iter_max)
		pixel_put(p, rgb((char)p->r, (char)p->g, (char)((p->b * i) / p->iter_max)));
	else
		pixel_put(p, rgb((char)((i * p->r2) / p->iter_max), (char)((i * p->g2) / p->iter_max), (char)((i * p->b2) / p->iter_max)));
}

void ft_random_fabs(t_param *p)
{

	p->y = 0;
	while (p->y < HT)
	{
		p->x = 0;
		while (p->x < WH)
		{
			calculate_ft_random_fabs(p);
			p->x++;
		}
		p->y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
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
		pixel_put(p, rgb((char)p->r, (char)p->g, (char)((p->b * i) / p->iter_max)));
	else
		pixel_put(p, rgb((char)((i * p->r2) / p->iter_max), (char)((i * p->g2) / p->iter_max), (char)((i * p->b2) / p->iter_max)));
}

void mandelbrot(t_param *p)
{

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

void	calculate_julia(t_param *p)
{
	int		i;

	i = 0;
	double	tmp;
	p->z_r = (p->x - p->zoom_x) * p->zoom;
	p->z_i = (p->y - p->zoom_y) * p->zoom;
	while (p->z_r * p->z_r + p->z_i * p->z_i <= 4 && i < p->iter_max)
	{
		tmp = p->z_r;
		p->z_r = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r;
		p->z_i = 2 * p->z_i * tmp + p->c_i;
		i++;
	}
	if (i == p->iter_max)
		pixel_put(p, rgb((char)p->r, (char)p->g, (char)((p->b * i) / p->iter_max)));
	else
		pixel_put(p, rgb((char)((i * p->r2) / p->iter_max), (char)((i * p->g2) / p->iter_max), (char)((i * p->b2) / p->iter_max)));
}

void	julia(t_param *p)
{
	p->y = 0;
	while (p->y < HT)
	{
		p->x = 0;
		while (p->x < WH)
		{
			calculate_julia(p);
			p->x++;
		}
		p->y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	usage(void)
{
	ft_putendl("usage: how to use: ./fractol [-info]");
	ft_putendl("       Mandelbrot: ./fractol [-m, -M, -mandelbrot]");
	ft_putendl("       Julia:      ./fractol [-j, -J, -julia]");
	ft_putendl("       Bouddhabrot ./fractol [-b, -B, -bouddhabrot]");
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
	{
		p->fra = 2;
	}
	else if (ft_strcmp(p->argv, "-t") == 0 || ft_strcmp(p->argv, "-T") == 0
			|| ft_strcmp(p->argv, "-tangente") == 0)
				p->fra = 3;
 else if (ft_strcmp(p->argv, "-a") == 0 || ft_strcmp(p->argv, "-A") == 0
 			|| ft_strcmp(p->argv, "-absolue") == 0)
				p->fra = 4;
else if (ft_strcmp(p->argv, "-mv2") == 0 || ft_strcmp(p->argv, "-MV2") == 0
			|| ft_strcmp(p->argv, "-mandelbrot v2") == 0)
				p->fra = 5;
	else if (ft_strcmp(p->argv, "-info") == 0)
	{
		ft_putendl("\t\t__________________");
		ft_putendl("\t\t|                |");
		ft_putendl("\t\t|---USER GUIDE---|");
		ft_putendl("\t\t|                |");
		ft_putendl("\t\t|  ESC  :  quit  |");
		ft_putendl("\t\t|ARROWS : MOVING |");
		ft_putendl("\t\t| 0,1,2 : COLOR  |");
		ft_putendl("\t\t|  +,-  : ZOOM   |");
		ft_putendl("\t\t|________________|");
		exit (0);
	}
	else
		usage();
}

int		keycode(int k, t_param *p)
{
	// printf(" P is EQ [%p] IN KEY CODE\n", p);

	if (k == ESC)
	{
		exit(0);
	}
	if (k == UP)
		p->zoom_y -= 20;
	if (k == DOWN)
		p->zoom_y += 20;
	if (k == LEFT)
		p->zoom_x -= 20;
	if (k == RIGHT)
		p->zoom_x += 20;
	if (k == 69 && p->zoom > 0.000001)
		p->zoom -= 0.2	 * p->zoom;
	if (k == 78 &&  p->zoom < 0.2)
    p->zoom += 0.05 * p->zoom;
	if (k == 67)
		p->iter_max += 2;
		if (k == 75 && p->iter_max > 10)
			p->iter_max -= 2;
	if (k == 82)
		{
			p->r += 321;
			p->g += 321;
			p->b += 321;
		}
		if (k == 85)
		{
			p->r2 += 234;
			p->g2 += 234;
			p->b2 += 234;
		}
		if (k == 84)
		{
			p->r2 -= 234;
			p->g2 -= 234;
			p->b2 -= 234;
		}
	  if (k == 83)
	  {
	  	p->r += 231;
	  	p->g += 231;
	  	p->b += 231;
	  	p->r2 += 231;
	  	p->g2 += 231;
	  	p->b2 += 231;
	  }
	launcher(p);
	return (0);
}

int		mouse_move(int x, int y, t_param *p)
{
	p->c_r = (double)(x - WH / 2) / 500;
	p->c_i = (double)(y - HT / 2) / 500;
	launcher(p);
	return (0);
}

void scroll_zoom_in(int x, int y, t_param *p)
{
	printf("ZOOM[%f]i\n", p->zoom);
	if (x > WH / 2 && y > HT / 2 && p->zoom > 0.001)
	{
	 	p->zoom -= 0.2 * p->zoom;
	  p->zoom_y -= (y - HT / 2);
		p->zoom_x -= (x - WH / 2);
	}
	if (x < WH / 2 && y > HT / 2)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y -= (y - HT / 2);
		p->zoom_x += (x - WH / 2);
	}
	if (x < WH / 2 && y < HT / 2)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y -= (y - HT / 2);
		p->zoom_x -= (x - WH / 2);
	}
	if (x > WH / 2 && y < HT / 2)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y += (y - HT / 2);
		p->zoom_x -= (x - WH / 2);
	}
	else if (x > WH / 2 && y > HT / 2 && p->zoom < 0.001)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y -= 1.2 *(y - HT / 2);
		p->zoom_x -= 1.2 *(x - WH / 2);
	}
	if (x < WH / 2 && y > HT / 2)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y -= 1.2 * (y - HT / 2);
		p->zoom_x += 1.2 * (x - WH / 2);
	}
	if (x < WH / 2 && y < HT / 2)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y -= 1.2 * (y - HT / 2);
		p->zoom_x -= 1.2 * (x - WH / 2);
	}
	if (x > WH / 2 && y < HT / 2)
	{
		p->zoom -= 0.2 * p->zoom;
		p->zoom_y += 1.2 * (y - HT / 2);
		p->zoom_x -= 1.2 * (x - WH / 2);
	}
}

void scroll_zoom_out(int x, int y, t_param *p)
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
	printf("x[%d], y[%d]\n", x, y);
	if (k == 4 && p->zoom > 0.000001)
		scroll_zoom_in(x, y, p);
	if (k == 5 &&  p->zoom < 0.2)
		scroll_zoom_out(x, y, p);
	launcher(p);
	return (0);
}

void	mlx_stuff(t_param *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WH, HT, "Fractol");
	p->img = mlx_new_image(p->mlx, WH, HT);
	mlx_hook(p->win, 2, 0, keycode, p);
	mlx_hook(p->win, 6, 0, mouse_move, p);
	mlx_hook(p->win, 4, (1L<<2), &mouse_scroll, p);

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

}

void init_param(t_param *p)
{
		p->x	= 0;
		p->y	= 0;
		p->q	= 0;
		p->d	= 0;
		p->r	= 0;
		p->r2	= 0;
		p->g	= 0;
		p->g2	= 0;
		p->b	= 0;
		p->b2	= 0;
		p->zoom	= 0;
		p->iter_max	= 0;
		p->zoom_x	= 0;
		p->zoom_y	= 0;
		p->c_r	= 0;
		p->c_i	= 0;
		p->z_r	= 0;
		p->z_i	= 0;
		p->fra	= 0;
		p->ac	= 0;
		p->argv	= NULL;
		p->mlx	= NULL;
		p->win	= NULL;
		p->wh	= 0;
		p->ht	= 0;
		p->img	= NULL;
		p->bpp	= 0;
		p->sz_ln	= 0;
		p->endian	= 0;
}

int		main(int ac, char **av)
{
	t_param		*p;

	if (!(p = malloc(sizeof(t_param))))
		return (EXIT_FAILURE);
		init_param(p);
	// printf("Adresse ofP In BEGINING [%p]\n", p);
	// memset(p, 0, sizeof(t_param));
	p->argv = av[1];
	p->ac = ac;
	which_fractal(p);
	mlx_stuff(p);
	init(p);
	launcher(p);
	mlx_loop(p->mlx);
	return (0);
}
