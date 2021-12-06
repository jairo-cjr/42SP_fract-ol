/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:49:10 by jcaetano          #+#    #+#             */
/*   Updated: 2021/11/26 08:45:55 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

void	print_square(void *mlx_ptr, void *win_ptr, int h, int w);

typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
}				t_param;

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int	deal_key(int key, t_param *param)
{
	param->x++;
	printf("x: %d\n", param->x);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w;
	int		h;
	t_param	param;

	param_init(&param);
	h = 300;
	w = 300;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, w, h, "42");
	print_square(mlx_ptr, win_ptr, h, w);
	mlx_key_hook(win_ptr, deal_key, &param);
	mlx_loop(mlx_ptr);
}

void	print_square(void *mlx_ptr, void *win_ptr, int h, int w)
{
	for (int i = 0; i <= w; i++)
	{
		for (int j = 0; j <= h; j++)
		{
			if (j >= (h/2) && i <= (w/2) || j <= (h/2) && i >= (w/2))
				mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFFF00);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x000);
		}
	}
}
