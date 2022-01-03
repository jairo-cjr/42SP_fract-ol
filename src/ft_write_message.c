/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:14:29 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/03 09:48:00 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_write_message(const char *message)
{
	int		fd;
	char	*line;

	fd = open(message, O_RDONLY);
	while (1)
	{
		if (fd < 0)
			return ;
		line = get_next_line(fd);
		if (!line || !*line)
			break ;
		ft_putstr_fd(line, 1);
		free (line);
	}
	close (fd);
}
