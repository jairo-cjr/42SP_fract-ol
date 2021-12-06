/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:32:04 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/01 16:19:35 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
// #include "../../mlx_linux/mlx_int.h";
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		x;
}				t_vars;

int	key_release(int keycode, t_vars *vars);

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 119)
	{
		vars->x++;
		printf("%d | x = %d\n", keycode, vars->x);
	}
	else if (keycode == 115)
	{
		vars->x--;
		printf("%d | x = %d\n", keycode, vars->x);
	}
	else if (keycode == 65307 || keycode == 113)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		printf("Closing...");
		exit (0);
	}
	else
		printf("%d\n", keycode);
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode)
		printf("%d Key '%c' released!\n", keycode, keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.x = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920 / 3, 1080 / 3, "42");
	mlx_hook(vars.win, 2, 1, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	mlx_loop(vars.mlx);
}
