/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:40:30 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 13:40:32 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"

void	copy_view_pnt(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf)
{
	t_map	*map;

	map = vars_fdf->map;
	vars_fdf->view_cp[map->cur_i][map->cur_j].x = view_pnt->x;
	vars_fdf->view_cp[map->cur_i][map->cur_j].y = view_pnt->y;
}

void	reset_view_pnt(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf)
{
	t_map	*map;

	map = vars_fdf->map;
	view_pnt->x = vars_fdf->view_cp[map->cur_i][map->cur_j].x;
	view_pnt->y = vars_fdf->view_cp[map->cur_i][map->cur_j].y;
}

void	copy_wrld_point(t_world_pnt *w_pnt, t_map *map)
{
	map->world_cp[map->cur_i][map->cur_j].x = w_pnt->x;
	map->world_cp[map->cur_i][map->cur_j].y = w_pnt->y;
	map->world_cp[map->cur_i][map->cur_j].z = w_pnt->z;
}

void	reset_wrld_point(t_world_pnt *w_pnt, t_map *map)
{
	w_pnt->x = map->world_cp[map->cur_i][map->cur_j].x;
	w_pnt->y = map->world_cp[map->cur_i][map->cur_j].y;
	w_pnt->z = map->world_cp[map->cur_i][map->cur_j].z;
}
