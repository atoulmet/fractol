/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <atoulmet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:03:17 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/24 10:27:25 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_img		*burningship(t_img *f)
{
	if (f->zoomin == 0)
	{
		f->x1 = -2.1 + f->move_lr;
		f->x2 = 0.6 + f->move_lr;
		f->y1 = -1.8 + f->move_ud;
		f->y2 = 1.2 + f->move_ud;
		f->image_x = (f->x2 - f->x1) * (f->zoom * 1.2);
		f->image_y = (f->y2 - f->y1) * (f->zoom * 1.2);
	}
	f->z_r = 0;
	f->z_i = 0;
	f->c_r = f->x / f->zoom + f->x1;
	f->c_i = f->y / f->zoom + f->y1;
	return (f);
}

t_img				*get_burning(t_img *f)
{
	f = burningship(f);
	f->x = 0;
	while (f->x < f->image_x)
	{
		f->y = 0;
		while (f->y < f->image_y)
		{
			f->i = 25;
			f = burningship(f);
			while (((f->z_r * f->z_r) + (f->z_i * f->z_i) < 4)
					&& f->i < (f->iteration_max))
			{
				f->tmp = fabs(f->z_r * f->z_i);
				f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
				f->z_i = 2 * f->tmp + f->c_i;
				(f->i)++;
			}
			f = put_color_pixel(f);
			(f->y)++;
		}
		(f->x)++;
	}
	return (f);
}
