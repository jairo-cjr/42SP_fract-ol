/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:04:34 by jcaetano          #+#    #+#             */
/*   Updated: 2021/11/25 09:28:14 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

void	bitshift(int x, int y, int left);
int		create_trgb(int t, int r, int g, int b);
int		get_color(int trgb, char color);

int	main(void)
{
	int	trgb;
	int	t;

	trgb = create_trgb(5, 47, 51, 243);
	t = get_color(trgb, 't');
	printf("%d\n", t);
	bitshift(5, 24, 1);
	return (0);
}

void	bitshift(int x, int y, int left)
{
	if (left)
		printf("%d << %d = %d", x, y, x << y);
	else
		printf("%d >> %d = %d", x, y, x >> y);
	printf("\n");
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(int trgb, char color)
{
	if (color == 't')
		return (trgb & (0xFF << 24));
	if (color == 'r')
		return (trgb & (0xFF << 16));
	if (color == 'g')
		return (trgb & (0xFF << 8));
	if (color == 'b')
		return (trgb & 0xFF);
}
