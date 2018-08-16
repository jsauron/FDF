/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:54:13 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/11 23:13:39 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_center(t_env *e)
{
	int			len_y;
	int			len_x;
	t_point		*a;
	t_point		*b;

	len_y = e->map.len;
	len_x = e->map.lines[len_y - 1].len;
	a = &e->map.lines[0].points[0];
	b = &e->map.lines[len_y - 1].points[len_x - 1];
	e->center.x = (b->x + a->x) / 2;
	e->center.y = (b->y + a->y) / 2;
}

void	get_min_max(t_map *map, int z)
{
	if (z > map->z_max)
		map->z_max = z;
	if (z < map->z_min)
		map->z_min = z;
}

int		hexa_to_int(char *str)
{
	int		c;
	int		dec;
	int		i;

	i = 0;
	dec = 0;
	str += 2;
	c = (ft_strlen((const char *)str) - 1);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			str[i] -= 55;
		else if (str[i] >= 'a' && str[i] <= 'f')
			str[i] -= 87;
		else
			str[i] -= 48;
		dec += str[i] * pow(16, c);
		c--;
		i++;
	}
	return (dec);
}

void	split_hexa_z(char *str2, t_point *p)
{
	char	**str;

	str = ft_strsplit(str2, ',');
	if (!str[0] || !str[1] || str[2])
		map_invalid();
	if (ft_strncmp("0x", str[1], 2) != 0)
		map_invalid();
	(p->z = ft_atoi(str[0]) * H);
	(p->color = hexa_to_int(str[1]));
	free(str[0]);
	free(str[1]);
	free(str);
}
