/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:22:28 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/24 10:53:34 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_error(int flag)
{
	if (flag == GRAPH_FAIL)
	{
		ft_putendl("Graphic failure.");
		exit(0);
	}
	if (flag == MALLOC_ERROR)
	{
		ft_putendl("Malloc failure.");
		exit(0);
	}
	if (flag == ERROR_PARAM)
	{
		ft_putstr("Julia\t\t[ju]\nJulio\t\t[jio]\n");
		ft_putstr("Mandelbrodt\t[ma]\nCeltic\t\t[ce]\nBurning Ship\t[bu]\n");
		ft_putstr("Zoomin\t\t[Scroll Mouse+]\nZoomout\t\t[Scroll mouse-]\n");
		ft_putstr("More iteration\t[Key '+']\nLess iteration\t[Key '-']\n");
		ft_putstr("Freeze\t\t[Space]\n");
		ft_putstr("Move up\t\t[Up Arrow]\nMove down\t[Down Arrow]\n");
		ft_putstr("Move left\t[Left Arrow]\nMove right\t[Right Arrow]\n");
		exit(0);
	}
}
