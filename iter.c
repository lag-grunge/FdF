/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:26:49 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 14:26:50 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iter_world(t_map *map, void (*func)(), void *par)
{
	map->cur_i = 0;
	map->cur_j = 0;
	while (map->cur_i < map->width)
	{
		while (map->cur_j < map->length[map->cur_i])
		{
			func(&map->world[map->cur_i][map->cur_j], par);
			map->cur_j++;
		}
		map->cur_j = 0;
		map->cur_i++;
	}
}

void	iter_view(t_vars_fdf *vars_fdf, void (*func)(), void *par)
{
	t_map		*map;
	t_view_pnt	**view;

	map = vars_fdf->map;
	view = vars_fdf->view;
	map->cur_i = 0;
	map->cur_j = 0;
	while (map->cur_i < map->width)
	{
		while (map->cur_j < map->length[map->cur_i])
		{
			func(&view[map->cur_i][map->cur_j], par);
			map->cur_j++;
		}
		map->cur_j = 0;
		map->cur_i++;
	}
}
