/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 19:35:02 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/11 19:44:10 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <sys/stat.h>
# include "../libft/includes/get_next_line.h"

/*
**	 Color text
*/

# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_GRAY         "\033[37m"

/*
**	 Color RGB
*/

# define BLUE 43263
# define RED 16711680
# define GREEN 65280
# define YELLOW 16776960
# define PINK 16754943
# define WHITE 16514043
# define CYAN 6881279

/*
**	 Params
*/

# define WIN_L 1280
# define WIN_H 960
# define SIZE_L 10
# define SIZE_H 10
# define H  3
# define ZOOM_B  1.1
# define ZOOM_S 0.9
# define BETA 0.1

/*
**	Key
*/

# define K_ESC 53
# define K_UP  126
# define K_DN  125
# define K_LT  123
# define K_RT  124
# define K_ROT_X 7
# define K_ROT_Y 16
# define K_ROT_Z 6
# define K_COLOR   257
# define K_ZOOM_B 24
# define K_ZOOM_S 44

/*
**	struct
*/

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
	int			hexa;

}				t_point;

typedef struct	s_line
{
	t_point		*points;
	int			len;

}				t_line;

typedef struct	s_map
{
	t_line		*lines;
	int			len;
	int			z_max;
	int			z_min;

}				t_map;

typedef struct	s_matrice
{
	double		x_a;
	double		x_b;
	double		x_c;
	double		y_a;
	double		y_b;
	double		y_c;
	double		z_a;
	double		z_b;
	double		z_c;
	double		x_z;
	double		y_z;
	double		z_z;

}				t_matrice;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			bppx;
	int			endian;
	int			x;
	int			y;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		image[2];
	t_map		map;
	t_point		center;
	t_matrice	m;
	char		*name;

}				t_env;

/*
**	 	Error.c
*/

void			err_malloc(void);
void			arg_invalid(void);
void			map_invalid(void);
void			image_err(void);
void			check_valid_map(char buff);

/*
**	 	Parsing.c
*/

void			parse_color(char **str2, t_point *p, int i);
int				parse_point(char *str, int line_nb,
		t_point **points, t_map *map);
void			parse_line(t_map *map, t_line *lines, int fd, char **av);
void			parse_map(char **av, t_map *map);

/*
**	 	matrice.c
*/

void			rot_x(t_env *e);
void			rot_y(t_env *e);
void			rot_z(t_env *e);
void			zoom(t_env *e, double zoom);
void			move(t_env *e, int move_x, int move_y);

/*
**	 	calc_matrice.c
*/

void			calc_all_points(t_env *e, t_matrice *m);
void			calc_matrice(t_env *e, t_matrice *m, t_point *p);

/*
**	 	tools.c
*/

void			get_center(t_env *e);
void			get_min_max(t_map *map, int z);
int				hexa_to_int(char *str);
void			split_hexa_z(char *str2, t_point *p);

/*
**	 	drawing.c
*/

void			brensenham_tab(int *tab, t_point p1, t_point p2);
void			draw_pixel(t_env *e, t_point p1, t_point p2, int color);
void			draw_line(t_env *e, t_point p1, int x, int y);
void			draw_map(t_env *e);

/*
**	 	hook.c
*/

int				key(int key, t_env *e);
void			key_move(t_env *e, int key);
void			key_rot(t_env *e, int key);
void			key_zoom(t_env *e, int key);

/*
**	 	image.c
*/

void			set_pixel_img(t_img *image, double x, double y, int color);
void			clear_img(t_env *image);
void			put_frame(t_env *e);
void			put_info_in_frame(t_env *e);

/*
**	 	color.c
*/

void			change_color(t_env *e);
int				get_color(t_map *map, t_point p, int n);
int				define_color(int n);

/*
**	 	init.c
*/

void			check_map(int ac, char **av, t_env *e);
void			init_win(t_env *e);
void			init_img(t_env *e);
void			exit_win(t_env *e);

#endif
