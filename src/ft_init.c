/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:59:30 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/01 21:39:56 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(int argc, char **argv, t_data *data)
{
	if (!ft_strcmp(data->title, "mandelbrot"))
		data->fractal = MANDELBROT;
	else if (!ft_strcmp(data->title, "julia") && argc == 4)
	{
		data->fractal = JULIA;
		data->k.re = ft_atof(argv[2]);
		data->k.im = ft_atof(argv[3]);
	}
	else
	{
		printf("Argumentos inválidos.\n");
		ft_clear_memory(data);
	}
	ft_init_mlx(data);
	ft_render(data);
}
