/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 21:20:48 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/11 22:23:05 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	err_malloc(void)
{
	ft_putstr(C_RED"Malloc failled\n"C_NONE);
	exit(1);
}

void	arg_invalid(void)
{
	ft_putstr(C_GREEN"./fdf <file>\n"C_NONE);
	exit(1);
}

void	map_invalid(void)
{
	ft_putstr(C_RED"Map invalid\n"C_NONE);
	exit(1);
}

void	image_err(void)
{
	ft_putstr(C_RED"Image failled\n"C_NONE);
	exit(1);
}

void	check_valid_map(char buff)
{
	if (!(ft_isdigit(buff) | ft_isspace(buff) || buff == '-' || buff == ',' ||
			buff == 'x' || (buff >= 'A' && buff <= 'F') ||
			(buff >= 'a' && buff <= 'f')))
		map_invalid();
}
