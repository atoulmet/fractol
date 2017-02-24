/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <atoulmet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:36:46 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/24 10:40:31 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_img	*put_pixel(t_img *img, int x, int y, int color)
{
	int		index;
	int		i;

	i = 0;
	index = y * img->size_line + x * (img->bits_per_pixel / 8);
	while (i < (img->bits_per_pixel / 8))
	{
		img->data_addr[index + i] = *((char*)&(color) + i);
		i++;
	}
	return (img);
}

t_img			*put_color_pixel(t_img *f)
{
	if (f->param == MANDELBRODT || f->param == JULIO || f->param == JULIA)
	{
		if (f->i >= f->iteration_max && f->x < WIN_W && f->y < WIN_H)
			put_pixel(f, f->x, f->y, f->col1);
		else if (f->i >= 80 && f->i < 100 && f->x < WIN_W && f->y < WIN_H)
			put_pixel(f, f->x, f->y, f->col2);
		else if (f->i >= 60 && f->i < 80 && f->x < WIN_W && f->y < WIN_H)
			put_pixel(f, f->x, f->y, f->col3);
		else if (f->i >= 40 && f->i < 60 && f->x < WIN_W && f->y < WIN_H)
			put_pixel(f, f->x, f->y, f->col4);
		else if (f->i > 30 && f->i < 40 && f->x < WIN_W && f->y < WIN_H)
			put_pixel(f, f->x, f->y, f->col5);
	}
	else
	{
		if (f->i >= f->iteration_max && f->x < WIN_W && f->y < WIN_H)
			put_pixel(f, f->x, f->y, f->col1);
		else if (f->i >= 40 && f->i < 49 && f->x < WIN_W && f->y < WIN_H)
			put_pixel(f, f->x, f->y, f->col2);
		else if (f->i >= 35 && f->i < 40 && f->x < WIN_W && f->y < WIN_H)
			put_pixel(f, f->x, f->y, f->col3);
		else if (f->i < 35 && f->x < WIN_W && f->y < WIN_H)
			put_pixel(f, f->x, f->y, f->col4);
	}
	return (f);
}
