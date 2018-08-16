/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 02:36:29 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/11 19:00:20 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_map(int ac, char **av, t_env *e)
{
	if (ac != 2)
		arg_invalid();
	e->name = (ft_strrchr(av[1], '/') + 1);
	e->map.z_max = 1;
	e->map.z_min = -1;
	parse_map(av, &e->map);
}

void	init_win(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_L, WIN_H, "FDF 42");
	get_center(e);
}

void	init_img(t_env *e)
{
	e->image[0].img = mlx_new_image(e->mlx, WIN_L, WIN_H);
	e->image[0].data = (int *)mlx_get_data_addr(e->image[0].img,
			&e->image[0].bpp, &e->image[0].size_l, &e->image[0].endian);
	if (!(e->image[1].img = mlx_xpm_file_to_image(e->mlx,
			"./xpm/5.xpm", &e->image[1].x, &e->image[1].y)))
		image_err();
	e->image[1].data = (int *)mlx_get_data_addr(e->image[1].img,
			&e->image[1].bpp, &e->image[1].size_l, &e->image[1].endian);
}

void	exit_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(1);
}
