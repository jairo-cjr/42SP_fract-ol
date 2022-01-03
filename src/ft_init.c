/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:59:30 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/03 09:02:36 by jcaetano         ###   ########.fr       */
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
			printf("Argumentos escritos de forma incorreta. Utilize para \
				visualizar um fractal julia diferente.\n");
		else
		{
			data->k.re = ft_atof(argv[2]);
			data->k.im = ft_atof(argv[3]);
		}
		data->fractal = JULIA;
	}
	else
	{
		printf("Argumentos inválidos.\n");
		ft_clear_memory(data);
	}
	ft_init_mlx(data);
	ft_render(data);
}
