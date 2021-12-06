/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:50:40 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/06 11:49:37 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./mlx_linux/mlx.h"
#include <stdlib.h>
#include <time.h>

#define WIN_WIDTH 900
#define WIN_HEIGHT 900

#define IMG_WIDTH 900
#define IMG_HEIGHT 900

#define MAX 80

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

int	main(void)
{
	t_mlx	*mlx;
	t_img	img;
	double	x_new;
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	int		iteration;
	int		row;
	int		col;
	int		count;
	double	color;
	int		iteration2;
//	int		max;

	mlx = malloc(sizeof(t_mlx) * 1);
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"A simple example");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l,
			&img.endian);
	row = 0;
	count = 0;
	iteration2 = 0;
	while (row < IMG_HEIGHT)
	{
		col = 0;
		while (col < IMG_WIDTH)
		{
			c_re = (row - IMG_WIDTH / 2.0) * 4.0 / IMG_WIDTH;
			c_im = (col - IMG_HEIGHT / 2.0) * 4.0 / IMG_WIDTH;
			x = 0;
			y = 0;
			iteration = 0;
			while (x * x + y * y <= 4 && iteration < 80)
			{
				x_new = x * x - y * y + c_re;
				y = 2 * x * y + c_im;
				x = x_new;
				iteration++;
				count++;
			}
			if (iteration < MAX)
			{
				color = 0xFF0 + (iteration * 30.05);
				img.data[col * IMG_WIDTH + row] = 0xFF0 + (iteration * 30.05);
				if (iteration2 != iteration && iteration >= 1)
				{
					printf("iterations: %d\tcolor: %.2f\tcolor2: %x\n", iteration, color, (int)color);
					iteration2 = iteration;
				}
			}
			else
			{
				color = 0xFFF;
				img.data[col * IMG_WIDTH + row] = color;
			}
			col++;
		}
		row++;
	}
	printf("count: %d\n", count);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
