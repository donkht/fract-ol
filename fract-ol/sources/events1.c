/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:12:39 by nleyton           #+#    #+#             */
/*   Updated: 2021/11/01 21:44:36 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move(int key, t_fractol *fractol)
{
	t_complex	step;

	step = init_complex(0.2, 0.2);
	if (key == KEY_LEFT)
	{
		fractol->min.re -= step.re;
		fractol->max.re -= step.re;
	}
	if (key == KEY_RIGHT)
	{
		fractol->min.re += step.re;
		fractol->max.re += step.re;
	}
	if (key == KEY_UP)
	{
		fractol->min.im += step.im;
		fractol->max.im += step.im;
	}
	if (key == KEY_DOWN)
	{
		fractol->min.im -= step.im;
		fractol->max.im -= step.im;
	}
	draw(fractol);
}

static void	color_range_shift(t_fractol *fractol)
{
	fractol->color_shift = (fractol->color_shift + 1) % 3;
	draw(fractol);
}

int	key_press(int key, t_fractol *fractol)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_LEFT || key == KEY_RIGHT
		|| key == KEY_UP || key == KEY_DOWN)
		move(key, fractol);
	else if (key == KEY_C)
		color_range_shift(fractol);
	return (0);
}

int	close(void)
{
	exit(0);
}
