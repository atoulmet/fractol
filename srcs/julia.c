/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 19:48:02 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/24 10:33:43 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_img		*julia(t_img *f)
{
	if (f->zoomin == 0)
	{
		f->x1 = -1 + f->move_lr;
		f->x2 = 4 + f->move_lr;
		f->y1 = -1.2 + f->move_ud;
		f->y2 = 1.2 + f->move_ud;
		if (f->move_mouse == 0)
		{
			f->c_r = 0.285;
			f->c_i = 0.01;
		}
		f->image_x = (f->x2 - f->x1) * (f->zoom * 1.2);
		f->image_y = (f->y2 - f->y1) * (f->zoom * 1.2);
	}
	f->z_r = f->x / f->zoom + f->x1;
	f->z_i = f->y / f->zoom + f->y1;
	return (f);
}

t_img				*get_julia(t_img *f)
{
	f = julia(f);
	f->x = 0;
	while (f->x < f->image_x)
	{
		f->y = 0;
		while (f->y < f->image_y)
		{
			f->i = 25;
			f = julia(f);
			while (((f->z_r * f->z_r) + (f->z_i * f->z_i) < 2)
					&& f->i < (f->iteration_max))
			{
				f->tmp = f->z_r;
				f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
				f->z_i = 2 * f->z_i * f->tmp + f->c_i;
				(f->i)++;
			}
			f = put_color_pixel(f);
			(f->y)++;
		}
		(f->x)++;
	}
	return (f);
}
