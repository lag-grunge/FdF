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
	view_pnt->x = w.x;
	view_pnt->y = w.y;
	view_pnt->color = map->color[i][j];
}

static void	init_screen(t_vars_fdf *vars_fdf)
{
	vars_fdf->screen_min.x = INFINITY;
	vars_fdf->screen_min.y = INFINITY;
	vars_fdf->screen_max.x = -INFINITY;
	vars_fdf->screen_max.y = -INFINITY;
}

void	projection(t_vars_fdf *vars_fdf)
{
	iter_world(vars_fdf->map, copy_wrld_point, vars_fdf->map);
	iter_world(vars_fdf->map, dot1x2, vars_fdf->camera.transformation);
	init_screen(vars_fdf);
	if (!vars_fdf->view)
	{
		init_view(&vars_fdf->view, vars_fdf);
		init_view(&vars_fdf->view_cp, vars_fdf);
	}
	iter_view(vars_fdf, comp_view_pnt, vars_fdf);
	iter_view(vars_fdf, find_max_min_view, vars_fdf);
	iter_view(vars_fdf, minus_inplace_v, &vars_fdf->screen_min);
/*
	iter_view(vars_fdf, copy_view_pnt, vars_fdf);
*/
	minus_inplace_v(&vars_fdf->screen_max, &vars_fdf->screen_min);
	vars_fdf->screen_min.x = 0;
	vars_fdf->screen_min.y = 0;
	iter_world(vars_fdf->map, reset_wrld_point, vars_fdf->map);
}
