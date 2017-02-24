/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 20:01:58 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/23 19:37:48 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img		*zoom_in(t_img *f)
{
	double	zbf;

	f->zoomin = 1;
	zbf = f->zoom;
	f->zoom = f->zoom * 1.2;
	f->iteration_max += 5;
	f->x1 += ((f->mouse_x / zbf) - (f->mouse_x / f->zoom));
	f->y1 += (f->mouse_y / zbf) - (f->mouse_y / f->zoom);
	return (f);
}

t_img		*zoom_out(t_img *f)
{
	double	zbf;

	f->zoomin = -1;
	zbf = f->zoom;
	f->zoom = f->zoom / 1.2;
	f->iteration_max -= 5;
	f->x1 += (f->mouse_x / zbf) - (f->mouse_x / f->zoom);
	f->y1 += (f->mouse_y / zbf) - (f->mouse_y / f->zoom);
	return (f);
}
