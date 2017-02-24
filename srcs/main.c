/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:23:01 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/23 16:21:03 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_img	*img;

	img = NULL;
	if (ac != 2)
		ft_error(ERROR_PARAM);
	img = env_init(img, av);
	img = init_color(img);
	img = init_img(img);
	img = choose_fract(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
	put_string(img);
	events(img);
	mlx_loop(img->mlx);
}
