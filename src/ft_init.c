/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:59:30 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/04 13:57:19 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(int argc, char **argv, t_data *data)
{
	if (!ft_strcmp(data->title, "mandelbrot"))
		data->fractal = MANDELBROT;
	else if (!ft_strcmp(data->title, "julia"))
	{
		if (argc != 4)
		{
			ft_write_error(JULIA_WARNING);
			data->k = ft_init_complex(0.285, 0.01);
		}
		else
			data->k = ft_init_complex(ft_atof(argv[2]), ft_atof(argv[3]));
		data->fractal = JULIA;
	}
	else
	{
		ft_write_error(MISSING_ARG);
		ft_clear_memory(data);
	}
	ft_init_mlx(data);
	ft_set_defaults(data);
	ft_render(data);
}
