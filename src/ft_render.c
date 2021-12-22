/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:29:22 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/22 07:00:20 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_render(t_data *data)
{
	int	color;

	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	color = ft_encode_rgb(66, 66, 66);
	ft_render_background(data->img, color);
	color = ft_encode_rgb(89, 108, 145);
	ft_render_rectangle(data->img, (t_rectangle){W - 100, H - 100,
		100, 100, color});
	color = ft_encode_rgb(147, 34, 185);
	ft_render_rectangle(data->img, (t_rectangle){0, 0, 100, 100, color});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr,
		0, 0);
	return (0);
}
