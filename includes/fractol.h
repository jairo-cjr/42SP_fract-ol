/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:06:21 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/04 14:07:14 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define W 800
# define H 800

# define MISSING_ARG	0
# define JULIA_WARNING	1

# define DESTROYNOT 17
# define KEYPRES 2
# define ESC_KEY 65307

# define MLX_ERROR 1

# define NMAX 200

# define MANDELBROT 0
# define JULIA 1

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_scale
{
	double	x_ratio;
	double	y_ratio;
	double	delta_x;
	double	delta_y;
	double	delta_x2;
	double	delta_y2;
}			t_scale;

typedef struct s_complex
{
	double			re;
	double			im;
	double			module;
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
	t_complex	k;
	int			x;
	int			y;
}				t_data;

int			ft_clear_memory(t_data *data);
void		ft_create_image(t_data *data);
void		ft_create_window(t_data *data);
int			ft_encode_trgb(double t, int r, int g, int b);
int			ft_get_color(int iterations);
int			ft_handle_keypress(int keysym, t_data *data);
void		ft_img_pixel_put(t_img *img, int x, int y, int color);
void		ft_init(int argc, char **argv, t_data *data);
t_complex	ft_init_complex(double re, double im);
void		ft_init_mlx(t_data *data);
void		ft_init_pointers(t_data *data);
void		ft_mandelbrot(t_data *data);
void		ft_julia(t_data *data);
int			ft_render(t_data *data);
void		ft_set_defaults(t_data *data);
void		ft_write_error(int erro);
void		ft_write_message(const char *message);
int			ft_zoom(int button, int x, int y, t_data *data);

#endif
