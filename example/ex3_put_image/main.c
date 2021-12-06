/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:49:10 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/02 09:36:25 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

/*
	After declaration, it will be automatically initialized when passed to
	mlx_get_data_addr().
*/
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print_squares(t_data *img, int w, int h, int num);
void	print_triangle(t_data *img, int w, int h);

int	main(void)
/*
	After creating an image, we can call `mlx_get_data_addr`, we pass
	`bits_per_pixel`, `line_length`, and `endian` by reference. These will
	then be set accordingly for the *current* data address.
*/
{
	void	*mlx;
	void	*mlx_win;
	int		w;
	int		h;
	t_data	img;

	w = 384;
	h = 216;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, w, h, "42");
	img.img = mlx_new_image(mlx, w, h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	print_squares(&img, w, h, w / 8);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_squares(t_data *img, int w, int h, int num)
{
	for (int i = 0; i <= w; i++)
	{
		for (int j = 0; j <= h; j++)
		{
			printf("i: %d, j: %d\n", i, j);
			if (j % num == 0 || i % num == 0)
				my_mlx_pixel_put(img, i, j, 0xFF5874);
			else
				my_mlx_pixel_put(img, i, j, 0x58FF74);
		}
	}
}
