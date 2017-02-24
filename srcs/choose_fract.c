/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:31:24 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/24 10:28:54 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img		*choose_fract(t_img *f)
{
	if (f->param == JULIA)
		f = get_julia(f);
	if (f->param == JULIO)
		f = get_julio(f);
	else if (f->param == BURNING)
		f = get_burning(f);
	else if (f->param == MANDELBRODT)
		f = get_mandel(f);
	else if (f->param == CELTIC)
		f = get_celtic(f);
	return (f);
}
