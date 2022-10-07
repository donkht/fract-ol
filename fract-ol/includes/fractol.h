/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:13:17 by nleyton           #+#    #+#             */
/*   Updated: 2021/11/01 21:46:02 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define SCROLL_UP			4
# define SCROLL_DOWN		5
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_ESC			53
# define KEY_C				8

typedef struct s_color
{
	char			channel[4];
}					t_color;

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
}					t_image;

typedef struct s_fractol
{
	void			*mlx;
	void			*window;
	t_image			*image;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	int				color_shift;
	int				(*formula)(struct s_fractol *fractol);
}					t_fractol;

void				ftbzero(void *s, size_t n);
t_image				*init_image(void *mlx);
t_complex			init_complex(double re, double im);
void				set_defaults(t_fractol *fractol);

void				draw(t_fractol *fractol);

int					mandelbrot(t_fractol *fractol);
int					julia(t_fractol *fractol);
int					burningship(t_fractol *fractol);

int					close(void);
int					key_press(int key, t_fractol *fractol);
int					zoom(int scroll, int x, int y, t_fractol *fractol);
int					motion(int x, int y, t_fractol *fractol);

#endif
