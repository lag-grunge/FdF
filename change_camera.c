/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:38:56 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 13:39:00 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	change_camera(t_vars_fdf *vars_fdf)
{
	vars_fdf->camera.octant++;
	iter_world(vars_fdf->map, reset_wrld_point, vars_fdf->map);
	vars_fdf->trans.x = 0;
	vars_fdf->trans.y = 0;
	init_camera(vars_fdf);
	projection(vars_fdf);
	vars_fdf->tile = calc_tile(vars_fdf, vars_fdf->tile);
	render_frame(vars_fdf);
	return (0);
}
