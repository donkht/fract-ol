/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:47:38 by nleyton           #+#    #+#             */
/*   Updated: 2021/11/01 21:44:37 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ftbzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		*((char *) s + i) = 0;
		i++;
	}
}

t_image	*init_image(void *mlx)
{
	t_image		*image;

	image = (t_image *)malloc(sizeof(t_image));
	ftbzero(image, sizeof(t_image));
	image->img = mlx_new_image(mlx, 1000, 1000);
	image->addr = mlx_get_data_addr(
			image->img, &(image->bits_per_pixel),
			&(image->line_lenght), &(image->endian));
	return (image);
}

t_complex	init_complex(double re, double im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}

void	set_defaults(t_fractol *fractol)
{
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max = init_complex(2.0, 2.0);
	fractol->k = init_complex(-0.4, 0.6);
	fractol->color_shift = 0;
}
