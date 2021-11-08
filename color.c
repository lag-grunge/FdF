/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:07:07 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 21:07:08 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_func(int color1, int color2, char c)
{
	int	x;
	int	y;

	if (c == 'r')
	{
		x = (color1 >> 16) & 0xFF;
		y = (color2 >> 16) & 0xFF;
	}
	else if (c == 'g')
	{
		x = (color1 >> 8) & 0xFF;
		y = (color2 >> 8) & 0xFF;
	}
	else if (c == 'b')
	{
		x = (color1) & 0xFF;
		y = (color2) & 0xFF;
	}
	else
		return (-1);
	return (y - x);
}

int	gradient_color(int color1, int color2, size_t i, size_t steps)
{
	int		color;
	int		dr;
	int		dg;
	int		db;
	double	x;

	if (color1 == color2)
		return (color1);
	dr = color_func(color1, color2, 'r');
	dg = color_func(color1, color2, 'g');
	db = color_func(color1, color2, 'b');
	x = (double)i / steps;
	color = color1;
	color |= (int)(x * (dr << 16));
	color |= (int)(x * (dg << 8));
	color |= (int)(x * db);
	return (color);
}
