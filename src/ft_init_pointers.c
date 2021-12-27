/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pointers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:21:27 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/27 12:51:36 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_pointers(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img.img_ptr = NULL;
	data->img.addr = NULL;
	data->min.re = 0.0;
	data->max.re = 0.0;
	data->min.im = 0.0;
	data->max.im = 0.0;
	data->factor.re = 0.0;
	data->factor.im = 0.0;
	data->c.re = 0.0;
	data->c.im = 0.0;
	data->x = 0;
	data->y = 0;
}
