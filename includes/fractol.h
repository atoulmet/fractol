/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:52:28 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/24 10:44:40 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <libft.h>
# include <time.h>

# define WIN_HEIGHT 800
# define WIN_WIDTH 800
# define WIN_H 800
# define WIN_W 800
# define WHITE 0X00FFFFFF
# define PURPLE2 0X008A0868
# define PURPLE 0X00DE00FF
# define DARK_BLUE 0X000A058E
# define DARKER_B 0X00030056
# define BLACK 0X00000000
# define MAGENTA 0X00FF00FF
# define YELLOW2 0X00F9FC3B
# define BLUE 0X000B173B
# define GREY 0X000B243B
# define RED 0X00DB0606
# define ORANGE 0X00E45E15

typedef struct	s_img
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*data_addr;
	int		param;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		height;
	int		width;
	int		col1;
	int		col2;
	int		col3;
	int		col4;
	int		col5;
	int		mouse_x;
	int		mouse_y;
	int		zoomin;
	int		move_mouse;
	float	move_lr;
	float	move_ud;
	int		freeze;
	int		x;
	int		y;
	int		i;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	zoom;
	int		iteration_max;
	float	image_x;
	float	image_y;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	float	tmp;
}				t_img;

enum
{
	GRAPH_FAIL,
	ERROR_PARAM,
	MALLOC_ERROR,
	MANDELBRODT,
	JULIA,
	JULIO,
	BURNING,
	CELTIC,
};

void			ft_error(int flag);
t_img			*init_fract(t_img *img);
float			zoom_compute(t_img *f, int less);
void			init_visual(int param);
int				events(t_img *img);
t_img			*put_color_pixel(t_img *img);
t_img			*init_img(t_img *img);
t_img			*env_init(t_img *img, char **av);
t_img			*zoom_in(t_img *f);
t_img			*zoom_out(t_img *f);
t_img			*init_color(t_img *img);
t_img			*choose_fract(t_img *f);
t_img			*get_mandel(t_img *f);
t_img			*get_julia(t_img *f);
t_img			*get_julio(t_img *f);
t_img			*get_burning(t_img *f);
t_img			*get_buddha(t_img *f);
t_img			*get_douady(t_img *f);
t_img			*get_celtic(t_img *f);
void			put_string(t_img *f);

#endif
