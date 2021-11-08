/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:37:47 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 14:37:48 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	comp_wrld_pnt(t_world_pnt *w_pnt, t_map *map)
{
	w_pnt->x = (double)(map->cur_j);
	w_pnt->y = (double)(map->cur_i);
	w_pnt->z = (double)(map->altus[map->cur_i][map->cur_j]);
}

void	model_world(t_map *map)
{
	init_world(&map->world, map);
	init_world(&map->world_cp, map);
	iter_world(map, comp_wrld_pnt, map);
	iter_world(map, minus_inplace, &map->world_min);
	minus_inplace(&map->world_max, &map->world_min);
	map->world_min.x = 0;
	map->world_min.y = 0;
	iter_world(map, copy_wrld_point, map);
	iter_world(map, find_max_min_world, map);
	map->world_center.x = map->world_max.x / 2;
	map->world_center.y = map->world_max.y / 2;
	map->world_center.z = map->world_max.z / 2;
}
