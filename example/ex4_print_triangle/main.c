/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:49:10 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/01 09:28:05 by jcaetano         ###   ########.fr       */
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
void	print_triangle(t_data *img, int w, int h);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		w;
	int		h;
	t_data	img;

	w = (192 * 10) / 2;
	h = (50 * 10) / 2;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, w, h, "42");
	img.img = mlx_new_image(mlx, w, h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	print_triangle(&img, w, h);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

void	print_triangle(t_data *img, int w, int h)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= h)
	{
		printf("i: %d | j: %d\n", i, j);
		k = 0;
		j = 0;
		while (j <= w / 2 - i) // 108 - 1 = 107
		{
			my_mlx_pixel_put(img, j, i, 0x58AFC4);
			j++;
		}
		while (k != 2 * (i + 1) - 1)
		{
			my_mlx_pixel_put(img, j, i, 0xFF5874);
			++k;
			++j;
		}
		while (j <= w)
		{
			my_mlx_pixel_put(img, j, i, 0x58AFC4);
			j++;
		}
		i++;
	}
}
