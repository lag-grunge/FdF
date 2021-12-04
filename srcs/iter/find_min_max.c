/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:36:54 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 14:36:56 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"

void	find_max_min_world(t_world_pnt *w_pnt, t_map *map)
{
	if (w_pnt->x < map->world_min.x)
		map->world_min.x = w_pnt->x;
	else if (w_pnt->x > map->world_max.x)
		map->world_max.x = w_pnt->x;
	if (w_pnt->y < map->world_min.y)
		map->world_min.y = w_pnt->y;
	else if (w_pnt->y > map->world_max.y)
		map->world_max.y = w_pnt->y;
	if (w_pnt->z < map->world_min.z)
		map->world_min.z = w_pnt->z;
	else if (w_pnt->z > map->world_max.z)
		map->world_max.z = w_pnt->z;
}

void	find_max_min_view(t_world_pnt *view_pnt, t_vars_fdf *vars_fdf)
{
	if (vars_fdf->screen_min.x > view_pnt->x)
		vars_fdf->screen_min.x = view_pnt->x;
	if (vars_fdf->screen_max.x < view_pnt->x)
		vars_fdf->screen_max.x = view_pnt->x;
	if (vars_fdf->screen_min.y > view_pnt->y)
		vars_fdf->screen_min.y = view_pnt->y;
	if (vars_fdf->screen_max.y < view_pnt->y)
		vars_fdf->screen_max.y = view_pnt->y;
}
