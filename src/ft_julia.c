/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:02:34 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/03 17:08:45 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_data *data)
{
	int			iter;
	t_complex	z;

	while (data->y < H)
	{
		data->c.im = data->max.im - (data->y * data->factor.im);
		data->x = 0;
		while (data->x < W)
		{
			data->c.re = data->min.re + (data->x * data->factor.re);
			z = ft_init_complex(data->c.re, data->c.im);
			z.module = pow(z.re, 2.0) + pow(z.im, 2.0);
			iter = 0;
			data->x++;
			while (z.module <= 4 && iter < NMAX)
			{
				z = ft_init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
						+ data->k.re, 2 * z.re * z.im + data->k.im);
				z.module = pow(z.re, 2.0) + pow(z.im, 2.0);
				iter++;
			}
			ft_img_pixel_put(&data->img, data->x, data->y, ft_get_color(iter));
		}
		data->y++;
	}
}
