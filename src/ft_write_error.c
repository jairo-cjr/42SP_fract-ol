/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:33:26 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/03 10:09:59 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_write_error(int erro)
{
	if (erro == MISSING_ARG)
		ft_write_message("./messages/missing_arguments.txt");
	if (erro == JULIA_WARNING)
		ft_write_message("./messages/julia_warning.txt");
}
