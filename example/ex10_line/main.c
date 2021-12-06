/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:32:04 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/03 14:49:29 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct s_param{
	void	*mlx;
	void	*win;
	int		begin_x;
	int		begin_y;
	int		end_x;
	int		end_y;
}		t_param;

int	draw_line(void *mlx, void *win, int begin_x, int begin_y, int end_x,
		int end_y,int color);

int	draw_line(void *mlx, void *win, int begin_x, int begin_y, int end_x,
		int end_y,int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = end_y - begin_x;
	delta_y = end_x - begin_y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = begin_x;
	pixel_y = begin_y;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

int	deal_key(int key, t_param *param)
{
	if (param->begin_x >= 0 || param->begin_y >= 0 || param->end_x >= 0 || param->end_y >= 0)
	{
		if (key == 'a')
		{
			param->begin_x++;
			param->begin_y++;
			printf("begin_x: %d\n", param->begin_x);
			printf("begin_y: %d\n", param->begin_y);
			draw_line(param->mlx, param->win, param->begin_x, param->begin_y, param->end_x,
				param->end_y, 0xFFFFFF);
		}
		else if (key == 's')
		{
			param->begin_x--;
			param->begin_y--;
			printf("begin_x: %d\n", param->begin_x);
			printf("end_x: %d\n", param->end_x);
			draw_line(param->mlx, param->win, param->begin_x, param->begin_y, param->end_x,
				param->end_y, 0xFFFFFF);
		}
		else if (key == 'd')
		{
			param->end_x++;
			param->end_y++;
			printf("end_x: %d\n", param->end_x);
			printf("end_y: %d\n", param->end_y);
			draw_line(param->mlx, param->win, param->begin_x, param->begin_y, param->end_x,
				param->end_y, 0xFFFFFF);
		}
		else if (key == 'f')
		{
			param->end_x--;
			param->end_y--;
			printf("end_x: %d\n", param->end_x);
			printf("end_y: %d\n", param->end_y);
			draw_line(param->mlx, param->win, param->begin_x, param->begin_y, param->end_x,
				param->end_y, 0xFFFFFF);
		}
		else if (key == 65307 || key == 113)
		{
			mlx_destroy_window(param->mlx, param);
			exit (0);
		}
		else
			printf("%d\n", key);
	}
	return (0);
}

int	main(void)
{
	t_param	param;

	param.begin_x = 1;
	param.begin_y = 1;
	param.end_y = 1;
	param.end_y = 1;
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 50, 50, "Draw Line 1");
	mlx_hook(param.win, 2, 1, &deal_key, &param);
	mlx_loop(param.mlx);
	return (0);
}
