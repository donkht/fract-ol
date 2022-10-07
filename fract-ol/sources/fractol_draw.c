/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:47:13 by nleyton           #+#    #+#             */
/*   Updated: 2021/11/01 21:44:23 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
	int	i;

	i = (x * fractol->image->bits_per_pixel / 8)
		+ (y * fractol->image->line_lenght);
	fractol->image->addr[i] = color.channel[3];
	fractol->image->addr[++i] = color.channel[2];
	fractol->image->addr[++i] = color.channel[1];
	fractol->image->addr[++i] = color.channel[0];
}

static t_color	get_color(int iteration, t_fractol *fractol)
{
	t_color	color;
	double	t;

	t = (double)iteration / 50;
	color.channel[0] = 0;
	color.channel[(0 + fractol->color_shift) % 3 + 1]
		= (char)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(1 + fractol->color_shift) % 3 + 1]
		= (char)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(2 + fractol->color_shift) % 3 + 1]
		= (char)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

void	draw(t_fractol *fractol)
{
	int			y;
	int			x;
	t_color		color;

	fractol->factor = init_complex(
			(fractol->max.re - fractol->min.re) / (1000 - 1),
			(fractol->max.im - fractol->min.im) / (1000 - 1));
	y = 0;
	while (y < 1000)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < 1000)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			color = get_color(fractol->formula(fractol), fractol);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image->img, 0, 0);
}
