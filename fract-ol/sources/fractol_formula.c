/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_formula.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:47:17 by nleyton           #+#    #+#             */
/*   Updated: 2021/11/01 21:44:28 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < 50)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->c.re,
				2.0 * z.re * z.im + fractol->c.im);
		iteration++;
	}
	return (iteration);
}

int	julia(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < 50)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->k.re,
				2.0 * z.re * z.im + fractol->k.im);
		iteration++;
	}
	return (iteration);
}

int	burningship(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < 50)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->c.re,
				-2.0 * fabs(z.re * z.im) + fractol->c.im);
		iteration++;
	}
	return (iteration);
}
