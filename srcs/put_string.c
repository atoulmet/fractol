/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <atoulmet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:28:11 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/23 19:33:49 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_string(t_img *f)
{
	char	*ite;

	ite = ft_itoa(f->iteration_max);
	if (f->param == MANDELBRODT)
		mlx_string_put(f->mlx, f->win, 10, 10, WHITE, "Mandelbrodt");
	if (f->param == JULIA)
		mlx_string_put(f->mlx, f->win, 10, 10, WHITE, "Julia");
	if (f->param == JULIO)
		mlx_string_put(f->mlx, f->win, 10, 10, WHITE, "Julio");
	if (f->param == BURNING)
		mlx_string_put(f->mlx, f->win, 10, 10, WHITE, "Burning Ship");
	if (f->param == CELTIC)
		mlx_string_put(f->mlx, f->win, 10, 10, WHITE, "Celtic");
	mlx_string_put(f->mlx, f->win, 10, 30, WHITE, "imax = ");
	mlx_string_put(f->mlx, f->win, 80, 30, WHITE, ite);
}
