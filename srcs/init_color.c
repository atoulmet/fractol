/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <atoulmet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:00:39 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/24 10:32:38 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img		*init_color(t_img *f)
{
	if (f->param == MANDELBRODT)
	{
		f->col1 = mlx_get_color_value(f->mlx, BLACK);
		f->col2 = mlx_get_color_value(f->mlx, BLACK);
		f->col3 = mlx_get_color_value(f->mlx, MAGENTA);
		f->col4 = mlx_get_color_value(f->mlx, YELLOW2);
		f->col5 = mlx_get_color_value(f->mlx, BLUE);
	}
	if (f->param == JULIA || f->param == JULIO)
	{
		f->col1 = mlx_get_color_value(f->mlx, PURPLE2);
		f->col2 = mlx_get_color_value(f->mlx, PURPLE);
		f->col3 = mlx_get_color_value(f->mlx, DARK_BLUE);
		f->col4 = mlx_get_color_value(f->mlx, DARKER_B);
		f->col5 = mlx_get_color_value(f->mlx, BLUE);
	}
	if (f->param == BURNING || f->param == CELTIC)
	{
		f->col1 = mlx_get_color_value(f->mlx, BLACK);
		f->col2 = mlx_get_color_value(f->mlx, ORANGE);
		f->col3 = mlx_get_color_value(f->mlx, RED);
		f->col4 = mlx_get_color_value(f->mlx, BLACK);
		f->col5 = mlx_get_color_value(f->mlx, RED);
	}
	return (f);
}
