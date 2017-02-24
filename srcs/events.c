/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:12:18 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/24 10:26:03 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img			*restart_img(t_img *img)
{
	mlx_destroy_image(img->mlx, img->img_ptr);
	img = init_img(img);
	img = choose_fract(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
	put_string(img);
	return (img);
}

static int		key_hook(int keycode, t_img *img)
{
	if (keycode == 49)
		img->freeze *= -1;
	if (keycode == 123)
		img->move_lr += 0.01;
	if (keycode == 124)
		img->move_lr -= 0.01;
	if (keycode == 126)
		img->move_ud += 0.01;
	if (keycode == 125)
		img->move_ud -= 0.01;
	if (keycode == 69)
		img->iteration_max += 10;
	if (keycode == 78)
		img->iteration_max -= 10;
	if (keycode == 49 || keycode == 123 || keycode == 124 || keycode == 126
			|| keycode == 125 || keycode == 69 || keycode == 78)
		restart_img(img);
	if (keycode == 53)
		exit(1);
	return (0);
}

static int		move_mouse(int x, int y, t_img *img)
{
	if (img->freeze == -1)
	{
		if (img->param == JULIO)
		{
			img->c_r = ((float)(x - 450) / 450);
			img->c_i = ((float)(y - 450) / 450);
		}
		else
		{
			img->c_r = ((float)(x - 400) / 400);
			img->c_i = ((float)(y - 400) / 400);
		}
		img->move_mouse = 1;
		restart_img(img);
	}
	return (0);
}

static int		mouse_hook(int button, int x, int y, t_img *img)
{
	if (button == 5)
	{
		img->mouse_x = x;
		img->mouse_y = y;
		zoom_in(img);
		img = restart_img(img);
	}
	if (button == 4)
	{
		img->mouse_x = x;
		img->mouse_y = y;
		zoom_out(img);
		img = restart_img(img);
	}
	return (0);
}

int				events(t_img *img)
{
	mlx_key_hook(img->win, key_hook, img);
	mlx_hook(img->win, 4, 0, mouse_hook, img);
	mlx_hook(img->win, 6, 0, move_mouse, img);
	return (0);
}
