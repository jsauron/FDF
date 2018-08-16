/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:54:03 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/11 22:02:49 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_pixel_img(t_img *image, double x, double y, int color)
{
	int i;

	if (x > 0 && x < WIN_L && y > 0 && y < WIN_H)
	{
		i = (int)x + (int)y * WIN_L;
		image->data[i] = color;
	}
}

void	clear_img(t_env *e)
{
	int		i;

	i = 0;
	while (i < WIN_H)
	{
		ft_memcpy(e->image[0].data + (i * WIN_L),
		e->image[1].data + (i * e->image[1].x), WIN_L * e->image[0].bpp / 8);
		i++;
	}
}

void	put_frame(t_env *e)
{
	int		x;
	int		y;

	x = 30;
	y = 30;
	while (x <= 300)
		set_pixel_img(e->image, x++, y, WHITE);
	while (y <= 140)
		set_pixel_img(e->image, x, y++, WHITE);
	while (x >= 30)
		set_pixel_img(e->image, x--, y, WHITE);
	while (y >= 30)
		set_pixel_img(e->image, x, y--, WHITE);
}

void	put_info_in_frame(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 50, 50, PINK, " Move  : arrows ");
	mlx_string_put(e->mlx, e->win, 50, 70, PINK, " Zoom  : + - ");
	mlx_string_put(e->mlx, e->win, 50, 90, PINK, " Rot   : x  y  z");
	mlx_string_put(e->mlx, e->win, 50, 110, PINK, " Color : shift");
	mlx_string_put(e->mlx, e->win, 60, 30, CYAN, e->name);
}
