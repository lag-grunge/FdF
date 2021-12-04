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

void	v_alloc_exit(t_view_pnt ***view, t_map *map, size_t i)
{
	if (*view)
	{
		free_2d_array(*view, i);
		*view = NULL;
		free_map(map);
		exit(malloc_error);
	}
	free_map(map);
	exit(malloc_error);
}

void	w_alloc_exit(t_world_pnt ***world, t_map *map, size_t i)
{
	if (*world)
	{
		free_2d_array(*world, i);
		*world = NULL;
		free_map(map);
		exit(malloc_error);
	}
	free_map(map);
	exit(malloc_error);
}
