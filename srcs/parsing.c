/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 23:41:53 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/11 22:45:14 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	parse_color(char **str2, t_point *p, int i)
{
	if (ft_strchr((const char *)str2[i], ','))
	{
		split_hexa_z(str2[i], p);
		p->hexa = 1;
	}
	else
	{
		(p->z = ft_atoi(str2[i]) * H);
		p->color = p->z;
	}
}

int		parse_point(char *str, int line_nb, t_point **points, t_map *map)
{
	t_point	*p;
	int		i;
	int		len;
	char	**str2;

	str2 = ft_strsplit(str, ' ');
	len = 0;
	while (str2[len])
		len++;
	if (!(*points = (t_point *)malloc(sizeof(t_point) * (len))))
		err_malloc();
	i = 0;
	while (str2[i])
	{
		p = *points + i;
		p->x = (i * SIZE_L + (WIN_L / 2) - (len * SIZE_L / 2));
		p->y = (line_nb * SIZE_H + (WIN_H / 2) - (map->len * SIZE_H / 2));
		parse_color(str2, p, i);
		get_min_max(map, p->z);
		free(str2[i]);
		i++;
	}
	free(str2);
	return (i);
}

void	parse_line(t_map *map, t_line *lines, int fd, char **av)
{
	int			line_nb;
	char		*str;
	t_point		*points;

	line_nb = 0;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		map_invalid();
	while (get_next_line(fd, &str) > 0)
	{
		lines[line_nb].len = parse_point(str, line_nb, &points, map);
		lines[line_nb].points = points;
		free(str);
		line_nb++;
	}
	close(fd);
}

void	parse_map(char **av, t_map *map)
{
	int			count_line;
	int			fd;
	char		buff;
	int			c;
	struct stat	sts;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		map_invalid();
	if (fstat(fd, &sts) != 0)
		map_invalid();
	if (!S_ISREG(sts.st_mode))
		map_invalid();
	count_line = 0;
	while ((read(fd, &buff, 1) > 0))
	{
		check_valid_map(buff);
		c == 0 ? count_line++ : count_line;
		c = 1;
		c = (buff == '\n') ? 0 : c;
	}
	close(fd);
	if (!(map->lines = (t_line *)malloc(sizeof(t_line) * count_line)))
		err_malloc();
	map->len = count_line;
	parse_line(map, map->lines, fd, av);
}
