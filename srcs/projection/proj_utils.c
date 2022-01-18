/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:14:39 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 07:06:48 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

static void	init_position(t_vars_fdf *vars_fdf, int change_proj)
{
	t_world_pnt	wmax;
	t_camera	*camera;
	int			octant;

	camera = &vars_fdf->camera;
	octant = camera->octant % 8;
	wmax = vars_fdf->map->world_max;
	if (vars_fdf->p == iso)
	{
		camera->position.x = 1.0;
		camera->position.y = 1.0;
		camera->position.z = 1.0;
	}
	else if (vars_fdf->p == psp && change_proj)
	{
		camera->position.x = wmax.x / 2.0;
		camera->position.y = find_max2i((int)wmax.y, \
		(int)wmax.z) / 2.0 / vars_fdf->tile * 4.0 * vars_fdf->tile_cp;
		camera->position.z = vars_fdf->map->world_min.z + (1 - 2 * (octant % 4 == 0)) * (wmax.z / 10. + 4.0);
	}
	camera->position.x *= (1 - 2 * (octant % 2 == 1));
	camera->position.y *= (1 - 2 * (octant % 4 == 2));
	camera->position.z *= (1 - 2 * (octant % 4 == 0));
}

void	init_camera(t_vars_fdf *vars_fdf, int change_proj)
{
	init_position(vars_fdf, change_proj);
	if (vars_fdf->p == iso)
	{
		vars_fdf->camera.target.x = 0;
		vars_fdf->camera.target.y = 0;
		vars_fdf->camera.target.z = 0;
	}
	else if (vars_fdf->p == psp)
	{
		vars_fdf->camera.target.x = vars_fdf->map->world_max.x / 2;
		vars_fdf->camera.target.y = vars_fdf->map->world_max.y / 2;
		vars_fdf->camera.target.z = vars_fdf->map->world_max.z / 2;
	}
	get_matrix(vars_fdf, vars_fdf->camera.transformation);
}
