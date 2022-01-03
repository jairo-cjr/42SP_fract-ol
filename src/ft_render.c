/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:29:22 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/03 16:23:23 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	if (data->fractal == MANDELBROT)
		ft_mandelbrot(data);
	if (data->fractal == JULIA)
		ft_julia(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr,
		0, 0);
	return (0);
}
