/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_defaults.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:11:36 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/03 16:30:36 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_defaults(t_data *data)
{
	if (data->fractal == MANDELBROT)
	{
		data->min = ft_init_complex(-2, -1.8);
		data->max.re = 1.5;
	}
	else if (data->fractal == JULIA)
	{
		data->min = ft_init_complex(-2.0, -2.0);
		data->max.re = 2.0;
	}
	data->max.im = data->min.im + (data->max.re - data->min.re) * H / W;
	data->factor.re = (data->max.re - data->min.re) / (W - 1);
	data->factor.im = (data->max.im - data->min.im) / (H - 1);
	if (!data->k.im || !data->k.re)
		data->k = ft_init_complex(-0.835, 0.232);
}
