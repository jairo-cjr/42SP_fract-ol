/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:06:21 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/27 16:41:55 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

# define W 600
# define H 600

# define MLX_ERROR 1

# define DESTROYNOT 17

# define NMAX 80

# define MANDELBROT 0
# define JULIA 1
# define BURNSHEEP 2

# define ESC 65307
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define C_KEY 99

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define ZOOM_IN 1
# define ZOOM_OUT -1

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*title;
	int			fractal;
	t_img		img;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	int			x;
	int			y;
}				t_data;

int			ft_clear_memory(t_data *data);
void		ft_create_image(t_data *data);
void		ft_create_window(t_data *data);
int			ft_encode_rgb(double t, int r, int g, int b);
int			ft_get_color(int iterations);
int			ft_handle_keypress(int keysym, t_data *data);
void		ft_img_pixel_put(t_img *img, int x, int y, int color);
void		ft_init(int argc, char **argv, t_data *data);
t_complex	ft_init_complex(double re, double im);
void		ft_init_mlx(t_data *data);
void		ft_init_pointers(t_data *data);
void		ft_mandelbrot(t_data *data);
// void		ft_render_background(t_img *img, int color);
// void		ft_render_rectangle(t_img *img, t_rectangle rect);
int			ft_render(t_data *data);

#endif
