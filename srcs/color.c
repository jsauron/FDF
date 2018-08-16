/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 01:12:57 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/11 19:26:23 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	change_color(t_env *e)
{
	define_color(1);
	clear_img(e);
	draw_map(e);
}

int		get_color(t_map *map, t_point p, int n)
{
	int			index;
	static int	c;
	const int	color[8] = {
		BLUE,
		PINK,
		CYAN,
		WHITE,
		YELLOW,
		PINK,
		CYAN,
		WHITE,
	};

	if (p.hexa == 1)
		return (p.color);
	c = c + n;
	c = (c > 7) ? 0 : c;
	if (p.color >= 0)
		index = c + p.color * 7 / map->z_max;
	else
		index = c + p.color * 7 / map->z_min;
	if (index > 7)
		index -= 8;
	return (color[index]);
}

int		define_color(int n)
{
	static int	c;
	int			color;

	if (c > 8)
		c = 0;
	if (c == 0)
		color = BLUE;
	if (c == 1)
		color = PINK;
	if (c == 2)
		color = CYAN;
	if (c == 3)
		color = WHITE;
	if (c == 4)
		color = YELLOW;
	if (c == 5)
		color = PINK;
	if (c == 6)
		color = CYAN;
	if (c == 7)
		color = WHITE;
	if (c == 8)
		color = PINK;
	c += n;
	return (color);
}
