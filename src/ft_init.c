/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:59:30 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/27 12:11:59 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(int argc, char **argv, t_data *data)
{
	if (!ft_strcmp(data->title, "mandelbrot"))
	{
		data->fractal = MANDELBROT;
		ft_init_mlx(data);
		ft_render(data);
		// ft_mandelbrot(data);
	}
	else if (!ft_strcmp(data->title, "julia"))
	{
		printf("Fractal de julia\n");
	}
	else
	{
		printf("Argumentos inválidos.\n");
		ft_clear_memory(data);
	}
	printf("Número de argumentos: %d\n", argc);
	printf("Title: %s\n", argv[1]);
}
