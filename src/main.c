/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:50:40 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/03 09:03:24 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*	[x]	Mandelbrot set
*	[x]	Julia set
*	[]	Zoom in e zoom out
*	[x]	Colorir o fractal
*	[]	Imprimir mensagem de erro se não haver parâmetros.
*	[x]	Sair com ESQ
*
*	Bônus
*	[]	Novo fractal
*	[] Zoom segue a posição do mouse
*	[] Cores alternam
*/

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
	{
		printf("Argumentos faltando.\n");
		exit(1);
	}
	else
	{
		data.title = (argv[1]);
		ft_init_pointers(&data);
		ft_init(argc, argv, &data);
	}
	mlx_loop_hook(data.mlx_ptr, &ft_render, &data);
	mlx_hook(data.win_ptr, DESTROYNOT, KeyPressMask, &ft_clear_memory, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_handle_keypress, &data);
	// mlx_expose_hook(data.mlx_ptr, &ft_render, &data);
	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);
}
