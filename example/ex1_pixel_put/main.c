/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:49:10 by jcaetano          #+#    #+#             */
/*   Updated: 2021/11/30 13:41:02 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w;
	int		h;

	w = 500;
	h = 500;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, w, h, "42");
	for (int i = 0; i <= w; i++)
	{
		for (int j = 0; j <= h; j++)
		{
			printf("i: %d, j: %d\n", i, j);
			if (j >= (h/2) && i <= (w/2) || j <= (h/2) && i >= (w/2))
				mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xEA526F);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x23B5D3);
		}
	}
	mlx_loop(mlx_ptr);
}
