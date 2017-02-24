/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:33:14 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/24 10:51:36 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		choose_param(char **av)
{
	if (ft_strncmp("ju\0", av[1], 3) == 0)
		return (JULIA);
	if (ft_strncmp("jio\0", av[1], 4) == 0)
		return (JULIO);
	if (ft_strncmp("ma\0", av[1], 3) == 0)
		return (MANDELBRODT);
	if (ft_strncmp("bu\0", av[1], 3) == 0)
		return (BURNING);
	if (ft_strncmp("ce\0", av[1], 3) == 0)
		return (CELTIC);
	else
		ft_error(ERROR_PARAM);
	exit(0);
}

static t_img	*it_max(t_img *img)
{
	if (img->param == MANDELBRODT || img->param == JULIA
			|| img->param == JULIO)
		img->iteration_max = 100;
	else
		img->iteration_max = 50;
	return (img);
}

t_img			*env_init(t_img *img, char **av)
{
	if ((img = (t_img*)ft_memalloc(sizeof(t_img))) == NULL)
		ft_error(MALLOC_ERROR);
	if ((img->mlx = mlx_init()) == NULL)
		ft_error(GRAPH_FAIL);
	if ((img->win = mlx_new_window(img->mlx, WIN_WIDTH,
					WIN_HEIGHT, "Fract'ol")) == NULL)
		ft_error(GRAPH_FAIL);
	img->height = WIN_HEIGHT;
	img->width = WIN_WIDTH;
	img->param = choose_param(av);
	img = it_max(img);
	img->zoom = 300;
	img->freeze = -1;
	return (img);
}

t_img			*init_img(t_img *img)
{
	if ((img->img_ptr = mlx_new_image(img->mlx, img->width,
					img->height)) == NULL)
		ft_error(GRAPH_FAIL);
	img->data_addr = mlx_get_data_addr(img->img_ptr, &(img->bits_per_pixel),
			&(img->size_line), &(img->endian));
	return (img);
}
