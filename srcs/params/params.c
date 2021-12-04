/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:09:11 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 15:09:12 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "params.h"

double	calc_tile(t_vars_fdf *vars_fdf, double start_tile)
{
	double	winx;
	double	winy;
	double	tile;

	winx = vars_fdf->win_x;
	winy = vars_fdf->win_y;
	tile = start_tile;
	if (vars_fdf->screen_max.x * tile > winx * BORDER)
		tile /= (vars_fdf->screen_max.x * tile / BORDER / winx);
	if (vars_fdf->screen_max.y * tile > winy * BORDER)
		tile /= (vars_fdf->screen_max.y * tile / BORDER / winy);
	return (tile);
}

void	get_win_sizes(t_vars_fdf *vars_fdf)
{
	double	scale;
	double	winx;
	double	winy;
	double	start_tile;

	start_tile = TILE_START;
	winx = vars_fdf->screen_max.x;
	winy = vars_fdf->screen_max.y;
	scale = (double)vars_fdf->screen_max.x / (double)vars_fdf->screen_max.y;
	scale *= (vars_fdf->screen_max.x * start_tile / winx);
	winx = max_size(SCREEN_WIDTH, &winy, SCREEN_HEIGHT, scale);
	if (winx == SCREEN_WIDTH)
		start_tile /= (vars_fdf->screen_max.x * start_tile / winx);
	scale /= (vars_fdf->screen_max.y * start_tile / winy);
	winy = max_size(SCREEN_HEIGHT, &winx, SCREEN_WIDTH, 1 / scale);
	if (winy == SCREEN_HEIGHT)
		start_tile /= (vars_fdf->screen_max.y * start_tile / winy);
	vars_fdf->win_x = ceil(winx) * 1.05;
	vars_fdf->win_y = ceil(winy) * 1.05;
	vars_fdf->tile = floor(start_tile);
	vars_fdf->tile_cp = vars_fdf->tile;
}
