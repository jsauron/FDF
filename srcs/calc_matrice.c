/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 23:47:22 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/11 18:56:20 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		calc_all_points(t_env *e, t_matrice *m)
{
	t_point	*p;
	int		x;
	int		y;

	y = 0;
	while (y < e->map.len)
	{
		x = 0;
		while (x < e->map.lines[y].len)
		{
			p = &e->map.lines[y].points[x];
			p->x -= e->center.x;
			p->y -= e->center.y;
			calc_matrice(e, m, p);
			x++;
		}
		y++;
	}
	clear_img(e);
	draw_map(e);
}

void		calc_matrice(t_env *e, t_matrice *m, t_point *p)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = (p->x * m->x_a) + (p->y * m->x_b) + (p->z * m->x_c) + m->x_z;
	new_y = (p->x * m->y_a) + (p->y * m->y_b) + (p->z * m->y_c) + m->y_z;
	new_z = (p->x * m->z_a) + (p->y * m->z_b) + (p->z * m->z_c) + m->z_z;
	p->x = new_x + e->center.x;
	p->y = new_y + e->center.y;
	p->z = new_z;
}
