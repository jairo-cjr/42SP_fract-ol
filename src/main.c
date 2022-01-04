/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:50:40 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/04 14:00:08 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
	{
		ft_write_error(MISSING_ARG);
		exit(MLX_ERROR);
	}
	else
	{
		data.title = (argv[1]);
		ft_init_pointers(&data);
		ft_init(argc, argv, &data);
	}
	mlx_hook(data.win_ptr, DESTROYNOT, 1L << 0, &ft_clear_memory, &data);
	mlx_hook(data.win_ptr, KEYPRES, 1L << 0, &ft_handle_keypress, &data);
	mlx_mouse_hook(data.win_ptr, ft_zoom, &data);
	mlx_expose_hook(data.win_ptr, &ft_render, &data);
	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);
}
