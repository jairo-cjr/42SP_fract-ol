/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_rectangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 03:26:57 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/22 06:52:14 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_render_rectangle(t_img *img, t_rectangle rect)
{
	int	x;
	int	y;

	y = rect.y;
	while (y < rect.y + rect.height)
	{
		x = rect.x;
		while (x < rect.x + rect.width)
		{
			ft_img_pixel_put(img, x, y, rect.color);
			++x;
		}
		++y;
	}
	return (0);
}
