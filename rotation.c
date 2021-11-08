/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:28:01 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 16:28:02 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_z(t_world_pnt *w)
{
	double	angle;
	double	tmp_x;

	angle = 2 * M_PI / 360;
	tmp_x = w->x;
	w->x = w->x * cos(angle) + w->y * (-sin(angle));
	w->y = tmp_x * sin(angle) + w->y * cos(angle);
}

int	comp_world_rotates(t_map *map)
{
	static int		time_elapsed;
	t_world_pnt		w_pnt_center_offset;
	static int		angle;

	time_elapsed++;
	if (time_elapsed % TIME_DELAY == 0)
	{
		angle++;
		w_pnt_center_offset.x = map->world_center.x;
		w_pnt_center_offset.y = map->world_center.y;
		w_pnt_center_offset.z = map->world_center.z;
		iter_world(map, minus_inplace, &w_pnt_center_offset);
		iter_world(map, rotation_z, NULL);
		iter_world(map, plus_inplace, &w_pnt_center_offset);
		return (1);
	}
	return (0);
}

int	rotate(t_vars_fdf *vars_fdf)
{
	t_map	*map;

	map = vars_fdf->map;
	if (vars_fdf->states.r_pressed)
	{
		if (comp_world_rotates(map))
		{
			projection(vars_fdf);
			vars_fdf->tile = calc_tile(vars_fdf, vars_fdf->tile);
			render_frame(vars_fdf);
		}
	}
	return (0);
}
