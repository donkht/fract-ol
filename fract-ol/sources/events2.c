/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:47:23 by nleyton           #+#    #+#             */
/*   Updated: 2021/11/01 21:44:37 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	scale_it(double start, double finish, double scale)
{
	return (start + ((finish - start) * scale));
}

int	zoom(int scroll, int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	double		scale;
	double		zoom;

	if (scroll == SCROLL_UP || scroll == SCROLL_DOWN)
	{
		mouse = init_complex(
				(double)x / (1000 / (fractol->max.re - fractol->min.re))
				+ fractol->min.re,
				(double)y / (1000 / (fractol->max.im - fractol->min.im))
				* -1 + fractol->max.im);
		if (scroll == SCROLL_UP)
			zoom = 0.75;
		else
			zoom = 1.25;
		scale = 1.0 / zoom;
		fractol->min.re = scale_it(mouse.re, fractol->min.re, scale);
		fractol->min.im = scale_it(mouse.im, fractol->min.im, scale);
		fractol->max.re = scale_it(mouse.re, fractol->max.re, scale);
		fractol->max.im = scale_it(mouse.im, fractol->max.im, scale);
		draw(fractol);
	}
	return (0);
}

int	motion(int x, int y, t_fractol *fractol)
{
	fractol->k = init_complex(
			4 * ((double)x / 1000 - 0.5),
			4 * ((double)(1000 - y) / 1000 - 0.5));
	draw(fractol);
	return (0);
}
