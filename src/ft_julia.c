/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:02:34 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/28 18:41:59 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_render_julia(t_data *data);
static void	ft_init_julia(t_data *data);

void	ft_julia(t_data *data)
{
	ft_init_julia(data);
	ft_render_julia(data);
}

static void	ft_render_julia(t_data *data)
{
	int			iter;
	t_complex	z;

	z = ft_init_complex(data->c.re, data->c.im);
	while (data->y < H)
	{
		data->x = 0;
		while (data->x < W)
		{
			z.module = 0.0;
			iter = 0;
			while (z.module <= 4 && iter < NMAX)
			{
				z = ft_init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
						+ data->c.re, 2 * z.re * z.im + data->c.im);
				z.module = pow(z.re, 2.0) + pow(z.im, 2.0);
				iter++;
			}
			data->x++;
			ft_img_pixel_put(&data->img, data->x, data->y, ft_get_color(iter));
		}
		data->y++;
	}
}

static void	ft_init_julia(t_data *data)
{
	data->c = ft_init_complex(-0.4, 0.6);
	data->min = ft_init_complex(-2.0, -2.0);
	data->max.re = 1.5;
	data->max.im = data->min.im + (data->max.re - data->min.re) * H / W;
	data->factor.re = (data->max.re - data->min.re) / (W - 1);
	data->factor.im = (data->max.im - data->min.im) / (H - 1);
}
