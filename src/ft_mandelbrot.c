/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:02:34 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/27 12:51:17 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_render_mandelbrot(t_data *data);
static void	ft_init_mandelbrot(t_data *data);
static int	ft_get_color(int iterations);

void	ft_mandelbrot(t_data *data)
{
	ft_init_mandelbrot(data);
	ft_render_mandelbrot(data);
}

static void	ft_render_mandelbrot(t_data *data)
{
	int	iter;
	t_complex z;

	while (data->y < H)
	{
		data->c.im = (data->max.im - data->y * data->factor.im);
		data->x = 0;
		while (data->x < W)
		{
			data->c.re = (data->min.re + data->x * data->factor.re);
			z = ft_init_complex(data->c.re, data->c.im);
			iter = 0;
			data->x++;
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iter < NMAX)
			{
				z = ft_init_complex(
						pow(z.re, 2.0) - pow(z.im, 2.0) + data->c.re,
						2 * z.re * z.im + data->c.im);
				iter++;
			}
			ft_img_pixel_put(&data->img, data->x, data->y, ft_get_color(iter));
		}
		data->y++;
	}
}

static void	ft_init_mandelbrot(t_data *data)
{
	data->min = ft_init_complex(-2.0, -2.0);
	data->max.re = 2.0;
	data->max.im = data->min.im + (data->max.re - data->min.re) * H / W;
	data->factor.re = (data->max.re - data->min.re) / (W - 1) * 1;
	data->factor.im = (data->max.im - data->min.im) / (H - 1) * 1;
}

static int	ft_get_color(int iterations)
{
	int	color;

	if (iterations < NMAX)
		return (ft_encode_rgb(255, 0, 0));
	else
	{
		return (ft_encode_rgb(255, 255, 255));
		return (color);
	}
}
