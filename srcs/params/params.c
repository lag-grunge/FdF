/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:09:11 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 07:20:05 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "params.h"

void	get_win_sizes(t_vars_fdf *vars_fdf)
{
	double	scale;
	double	winx;
	double	winy;
	double	start_tile;

	start_tile = TILE_START;
	winx = vars_fdf->screen_max.x - vars_fdf->screen_min.x;
	winy = vars_fdf->screen_max.y - vars_fdf->screen_min.y;
	scale = winx / winy;
	winx *= start_tile;
	winy *= start_tile;
	winx = max_size(SCREEN_WIDTH, &winy, SCREEN_HEIGHT, scale);
	winy = max_size(SCREEN_HEIGHT, &winx, SCREEN_WIDTH, 1 / scale);
	vars_fdf->win_x = ceil(winx);
	vars_fdf->win_y = ceil(winy);
	vars_fdf->tile = floor(start_tile);
	vars_fdf->tile_cp = vars_fdf->tile;
}

void	get_win_sizes2(t_vars_fdf *vars_fdf)
{
	double	scale;
	double	winx;
	double	winy;

	winx = vars_fdf->screen_max.x - vars_fdf->screen_min.x;
	winy = vars_fdf->screen_max.y - vars_fdf->screen_min.y;
	scale = winx / winy;
	if (scale >= SCREEN_WIDTH / (SCREEN_HEIGHT + .0))
	{
		winx = SCREEN_WIDTH * round(winx) / round(winx + 1);
		winy = (winx + .0) / scale;
		if (winy < MIN_WIN_SIZE)
			winy = MIN_WIN_SIZE;
	}
	else
	{
		winy = SCREEN_HEIGHT * round(winy) / round(winy + 1);
		winx = (winy + .0) * scale;
		if (winx < MIN_WIN_SIZE)
			winx = MIN_WIN_SIZE;
	}
	if (winx > vars_fdf->win_x)
		vars_fdf->win_x = winx;
	if (winy > vars_fdf->win_y)
		vars_fdf->win_y = winy;
}
