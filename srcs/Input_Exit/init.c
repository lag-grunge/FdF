/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:20:08 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 14:20:10 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input_Exit.h"

void	init_view(t_view_pnt ***v, t_vars_fdf *vars_fdf)
{
	t_view_pnt	**view;
	t_map		*map;
	size_t		i;

	i = 0;
	map = vars_fdf->map;
	view = (t_view_pnt **)malloc(sizeof(t_view_pnt *) * map->width);
	if (!view)
		v_alloc_exit(&view, map, i);
	while (i < map->width)
	{
		view[i] = malloc(sizeof(t_view_pnt) * map->length[i]);
		if (!view[i])
			v_alloc_exit(&view, map, i);
		i++;
	}
	*v = view;
}

void	init_world(t_world_pnt ***w, t_map *map)
{
	t_world_pnt	**world;
	size_t		i;

	i = 0;
	world = (t_world_pnt **)malloc(sizeof(t_world_pnt *) * map->width);
	if (!world)
		w_alloc_exit(&world, map, i);
	while (i < map->width)
	{
		world[i] = (t_world_pnt *)malloc(sizeof(t_world_pnt) * map->length[i]);
		if (!world[i])
			w_alloc_exit(&world, map, i);
		i++;
	}
	*w = world;
}
