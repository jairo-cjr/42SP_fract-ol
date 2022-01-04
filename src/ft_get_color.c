/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:36:05 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/04 13:32:37 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_get_color(int iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = pow(log((double)iterations), 2.0) / pow(log((double)NMAX), 2.0);
	r = (int)(9 * (1 - t) * pow(t, 3) * 150);
	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	b = (int)(8.5 * pow((1 - t), 3) * t * 80);
	return (ft_encode_trgb(t, r, g, b));
}
