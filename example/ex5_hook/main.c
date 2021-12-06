/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:32:04 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/01 10:32:03 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../../mlx_linux/mlx_int.h";
#include <stdio.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars);
int	mouse_hook(int button, int x, int y, t_vars *vars);
int	mouse_move_hook(int x, int y, t_vars *vars);
int	expose_hook(int exposecode, t_vars *vars);
int	loop_hook(int loopcode, t_vars *vars);

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_expose_hook (vars.win, expose_hook, &vars);
	mlx_hook(vars.win, MotionNotify, PointerMotionMask, mouse_move_hook, 0);
	mlx_loop(vars.mlx);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("key_hook %d!\n", keycode);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("mouse_hook, button %d at %dx%d.\n", button, x, y);
}

int	mouse_move_hook(int x, int y, t_vars *vars)
{
	printf("Mouse moving at %dx%d.\n", x, y);
}

int	expose_hook(int exposecode, t_vars *vars)
{
	printf("exposecode %d!\n", exposecode);
}

int	loop_hook(int loopcode, t_vars *vars)
{
	printf("loopcode %d!\n", loopcode);
}
