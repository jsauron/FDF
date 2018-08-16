/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 23:38:15 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/11 18:57:09 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key(int key, t_env *e)
{
	if (key == K_ESC)
		exit_win(e);
	if (key >= K_LT && key <= K_UP)
		key_move(e, key);
	if (key == K_ROT_X || key == K_ROT_Y || key == K_ROT_Z)
		key_rot(e, key);
	if (key == K_ZOOM_B || key == K_ZOOM_S)
		key_zoom(e, key);
	if (key == K_COLOR)
		change_color(e);
	printf("%d\n", key);
	return (0);
}

void	key_move(t_env *e, int key)
{
	if (key == K_UP)
		move(e, 0, -SIZE_H);
	if (key == K_DN)
		move(e, 0, SIZE_H);
	if (key == K_RT)
		move(e, SIZE_L, 0);
	if (key == K_LT)
		move(e, -SIZE_L, 0);
}

void	key_rot(t_env *e, int key)
{
	if (key == K_ROT_X)
		rot_x(e);
	if (key == K_ROT_Y)
		rot_y(e);
	if (key == K_ROT_Z)
		rot_z(e);
}

void	key_zoom(t_env *e, int key)
{
	if (key == K_ZOOM_B)
		zoom(e, ZOOM_B);
	else
		zoom(e, ZOOM_S);
}
