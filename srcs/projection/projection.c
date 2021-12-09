/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:15:33 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 16:15:35 by sdalton          ###   ########.fr       */
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
	if (vars_fdf->p == iso)
	{
		view_pnt->x = w.x;
		view_pnt->y = w.y;
	}
	else if (vars_fdf->p == psp)
	{
		if (w.z < 0)
		{
			view_pnt->x = - w.x / w.z;
			view_pnt->y = - w.y / w.z;
		}
		else
		{
			view_pnt->x = 0;
			view_pnt->y = 0;
		}
	}
	view_pnt->color = map->color[i][j];
}



static void	init_screen(t_vars_fdf *vars_fdf)
{
	vars_fdf->screen_min.x = INFINITY;
	vars_fdf->screen_min.y = INFINITY;
	vars_fdf->screen_max.x = -INFINITY;
	vars_fdf->screen_max.y = -INFINITY;
}

void	camera(t_vars_fdf *vars_fdf)
{
	iter_world(vars_fdf->map, dot1x2, vars_fdf->camera.transformation);
//	iter_world(vars_fdf->map, printiter, vars_fdf->map);
}

void	screen(t_vars_fdf *vars_fdf)
{
	iter_view(vars_fdf, comp_view_pnt, vars_fdf);
	init_screen(vars_fdf);
	iter_view(vars_fdf, find_max_min_view, vars_fdf);
	if (vars_fdf->p == psp)
		get_win_sizes2(vars_fdf);
	else if (vars_fdf->p == iso)
	{
		iter_view(vars_fdf, minus_inplace_v, &vars_fdf->screen_min);
		minus_inplace_v(&vars_fdf->screen_max, &vars_fdf->screen_min);
		vars_fdf->screen_min.x = 0;
		vars_fdf->screen_min.y = 0;
	}
}

static void raster_func(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf)
{
	view_pnt->x = (view_pnt->x + vars_fdf->win_x / 2.0) / vars_fdf->win_x;
	view_pnt->y = (view_pnt->y + vars_fdf->win_y / 2.0) / vars_fdf->win_y;
	view_pnt->x = view_pnt->x * vars_fdf->win_x;
	view_pnt->y = (1 - view_pnt->y) * vars_fdf->win_y;
}

void 	raster(t_vars_fdf *vars_fdf)
{
	iter_view(vars_fdf, raster_func, vars_fdf);
}

void	projection(t_vars_fdf *vars_fdf)
{
	iter_world(vars_fdf->map, copy_wrld_point, vars_fdf->map);
	camera(vars_fdf);
	screen(vars_fdf);
	if (vars_fdf->p == psp)
		raster(vars_fdf);
	iter_world(vars_fdf->map, reset_wrld_point, vars_fdf->map);
}
