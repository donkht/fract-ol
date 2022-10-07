/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:48:09 by nleyton           #+#    #+#             */
/*   Updated: 2021/11/01 23:34:51 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ftatoi(const char *str)
{
	int	i;
	int	ret;
	int	sign;

	i = 0;
	ret = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - 48;
		i++;
	}
	return (ret * sign);
}

static void	init_fractol(int (*frml)(t_fractol *fractol), char *t, t_complex k2)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	ftbzero(fractol, sizeof(t_fractol));
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, 1000, 1000, t);
	fractol->image = init_image(fractol->mlx);
	set_defaults(fractol);
	fractol->k = k2;
	fractol->formula = frml;
	mlx_hook(fractol->window, 2, 0, key_press, fractol);
	mlx_hook(fractol->window, 17, 0, close, fractol);
	mlx_hook(fractol->window, 4, 0, zoom, fractol);
	mlx_hook(fractol->window, 6, 0, motion, fractol);
	draw(fractol);
	mlx_loop(fractol->mlx);
}

static void	how_to_use(void)
{
	printf("Type for launch: ./fractol <parameter>\n");
	printf("You can use:\n\t<Mandelbrot>,\n");
	printf("\t<Julia> <x> <y> (where 0 < x/y < 1000)\n");
	printf("\t<Burning Ship>\n\n");
	printf("How to use the program:\n");
	printf("\tkey C - color range shift\n");
	printf("\tkey ESC - close program\n");
	printf("\tkeys arrow up/down and arrow right/left - move\n");
	printf("\tscroll mouse UP - zoom out\n");
	printf("\tscroll mouse DOWN - zoom in\n");
	printf("Enjoy!\n");
}

static int	is_equal(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_complex	k;

	k = init_complex(-0.4, 0.6);
	if (argc == 2)
	{
		if (is_equal(argv[1], "Mandelbrot"))
			init_fractol(&mandelbrot, "Mandelbrot", k);
		else if (is_equal(argv[1], "Julia"))
			init_fractol(&julia, "Julia", k);
		else if (is_equal(argv[1], "Burning Ship"))
			init_fractol(&burningship, "Burning Ship", k);
	}
	if (argc == 4)
	{
		if (argv[1][0] == 'j' || argv[1][0] == 'J')
		{
			k = init_complex(
					4 * ((double)ftatoi(argv[2]) / 1000 - 0.5),
					4 * ((double)(1000 - ftatoi(argv[3])) / 1000 - 0.5));
			init_fractol(&julia, "Julia", k);
		}
	}
	how_to_use();
	return (0);
}
