/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 05:40:35 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/27 11:37:11 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*	É necessário passar a img obtida para os três ultimos argumentos.
*	A função definirá o valor correto desses argumentos.
*	mlx_get_data_addr() retorna o endereço real da imagem como um array simples
*	de pixels. Por ser um ponteiro char, significa que percorremos 1 byte
*	por vez, oq é diferente de um píxel, que normalmente tem mais bytes.
*
*	bpp = bits per píxel. o valor correspondente ao tamanho do pixel.
*		bpp / 8 = converter para bytes, 1 byte = 8 bits
*
*	size_l = quantidade de bytes usados por uma linha da imagem.
*		size_l = width * (bpp / 8);
*		width = 600;
*		1 int = 4 bytes, logo size_l = width * 4 = 24000 bytes por linha
*		a 1º linha começa no indice 0 até 23999, e a 2º em 24000
*		para encontrar a 10 linha, basta fazer 10 * 24000
*		para encontrar a coluna 5, basta multiplicar pelo tamanho do pixel
*		em bytes. 5 * 4 = 20
*
*	Assim, para encontrar o indice correto de um píxel, basta realizar
*	index = size_l * pos_y + pos_x * (bpp / 8);
*/

void	ft_create_image(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, W, H);
	if (!data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.size_l, &data->img.endian);
	if (!data->img.addr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
}
