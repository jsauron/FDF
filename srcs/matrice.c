/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 00:21:52 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/05 04:42:00 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rot_x(t_env *e)
{
	t_matrice	m;

	m.x_a = 1;
	m.x_b = 0;
	m.x_c = 0;
	m.y_a = 0;
	m.y_b = cos(BETA);
	m.y_c = -sin(BETA);
	m.z_a = 0;
	m.z_b = sin(BETA);
	m.z_c = cos(BETA);
	m.x_z = 0;
	m.y_z = 0;
	m.z_z = 0;
	calc_all_points(e, &m);
}

void	rot_y(t_env *e)
{
	t_matrice	m;

	m.x_a = cos(BETA);
	m.x_b = 0;
	m.x_c = sin(BETA);
	m.y_a = 0;
	m.y_b = 1;
	m.y_c = 0;
	m.z_a = -sin(BETA);
	m.z_b = 0;
	m.z_c = cos(BETA);
	m.x_z = 0;
	m.y_z = 0;
	m.z_z = 0;
	calc_all_points(e, &m);
}

void	rot_z(t_env *e)
{
	t_matrice	m;

	m.x_a = cos(BETA);
	m.x_b = sin(BETA);
	m.x_c = 0;
	m.y_a = -sin(BETA);
	m.y_b = cos(BETA);
	m.y_c = 0;
	m.z_a = 0;
	m.z_b = 0;
	m.z_c = 1;
	m.x_z = 0;
	m.y_z = 0;
	m.z_z = 0;
	calc_all_points(e, &m);
}

void	zoom(t_env *e, double zoom)
{
	t_matrice	m;

	m.x_a = zoom;
	m.x_b = 0;
	m.x_c = 0;
	m.y_a = 0;
	m.y_b = zoom;
	m.y_c = 0;
	m.z_a = 0;
	m.z_b = 0;
	m.z_c = zoom;
	m.x_z = 0;
	m.y_z = 0;
	m.z_z = 0;
	calc_all_points(e, &m);
}

void	move(t_env *e, int move_x, int move_y)
{
	t_matrice	m;

	m.x_a = 1;
	m.x_b = 0;
	m.x_c = 0;
	m.y_a = 0;
	m.y_b = 1;
	m.y_c = 0;
	m.z_a = 0;
	m.z_b = 0;
	m.z_c = 1;
	m.x_z = move_x;
	m.y_z = move_y;
	m.z_z = 0;
	get_center(e);
	calc_all_points(e, &m);
}
