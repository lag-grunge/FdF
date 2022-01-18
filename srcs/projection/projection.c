/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:15:33 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 06:33:26 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

void	comp_view_pnt(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf)
{
	t_world_pnt	w;
	t_map		*map;
	size_t		i;
	size_t		j;

	map = vars_fdf->map;
	i = map->cur_i;
	j = map->cur_j;
	w = map->world[i][j];
	view_pnt->color = map->color[i][j];
	if (vars_fdf->p == iso)
	{
		view_pnt->x = w.x;
		view_pnt->y = w.y;
		return ;
	}
	else if (vars_fdf->p == psp && (w.z < -1))
	{
		view_pnt->x = -w.x * 1000. / w.z;
		view_pnt->y = -w.y * 1000. / w.z;
		return ;
	}
	view_pnt->x = nan("");
	view_pnt->y = nan("");
}

static void	screen(t_vars_fdf *vars_fdf)
{
	vars_fdf->screen_min.x = INFINITY;
	vars_fdf->screen_min.y = INFINITY;
	vars_fdf->screen_max.x = -INFINITY;
	vars_fdf->screen_max.y = -INFINITY;
	iter_view(vars_fdf, find_max_min_view, vars_fdf);
}

static void	raster_func(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf)
{
	if (vars_fdf->p == iso)
	{
		multi_inplace_v(view_pnt, &vars_fdf->tile);
		view_pnt->x = view_pnt->x + vars_fdf->win_x / 2.0;
		view_pnt->y = view_pnt->y + vars_fdf->win_y / 2.0;
	}
	else if (vars_fdf->p == psp)
	{
		view_pnt->x = (view_pnt->x + vars_fdf->win_x / 2.0) / vars_fdf->win_x;
		view_pnt->y = (view_pnt->y + vars_fdf->win_y / 2.0) / vars_fdf->win_y;
		view_pnt->x = view_pnt->x * vars_fdf->win_x;
		view_pnt->y = (1 - view_pnt->y) * vars_fdf->win_y;
	}
}

void	projection(t_vars_fdf *vars_fdf)
{
	iter_world(vars_fdf->map, copy_wrld_point, vars_fdf->map);
	iter_world(vars_fdf->map, dot1x2, vars_fdf->camera.transformation);
	iter_view(vars_fdf, comp_view_pnt, vars_fdf);
	screen(vars_fdf);
	if (!vars_fdf->win && vars_fdf->p == psp)
		get_win_sizes2(vars_fdf);
	iter_view(vars_fdf, raster_func, vars_fdf);
	iter_world(vars_fdf->map, reset_wrld_point, vars_fdf->map);
}
