/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:14:39 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 16:14:40 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

static void	calc_camera_z(t_world_pnt *c_z, t_world_pnt *c, t_world_pnt *t)
{
	c_z->x = c->x;
	c_z->y = c->y;
	c_z->z = c->z;
	minus_inplace(c_z, t);
	normalization(c_z);
//	c_z->x *= -1;
//	c_z->y *= -1;
//	c_z->z *= -1;
}

static void	calc_camera_x(t_world_pnt *c_x, t_world_pnt *c_z, int down)
{
	t_world_pnt	up;

	up.x = 0;
	up.y = 0;
	if (!down)
		up.z = 1;
	else
		up.z = -1;
	cross(c_x, c_z, &up);
	normalization(c_x);
}

static void	init_position(t_vars_fdf *vars_fdf) {
	int octant;
	t_camera *camera;

	camera = &vars_fdf->camera;
	if (vars_fdf->p == iso) {
		if (!camera->octant) {
			camera->position.x = 1.0;
			camera->position.y = 1.0;
			camera->position.z = 1.0;
			return;
		}
		octant = camera->octant % 8;
		camera->position.x *= (1 - 2 * (octant % 2 == 1));
		camera->position.y *= (1 - 2 * (octant % 4 == 2));
		camera->position.z *= (1 - 2 * (octant % 4 == 0));
	}
	else if (vars_fdf->p == psp)
	{
		camera->position.x = vars_fdf->map->world_max.x / 2.0;
		camera->position.y = vars_fdf->map->world_max.y / 2.0 * 3.0;
		camera->position.z = vars_fdf->map->world_max.z / 2.0;
	}
}

static void get_matrix(t_vars_fdf *vars_fdf, double camera_matrix[4][4])
{
	t_world_pnt camera_x_axis;
	t_world_pnt camera_y_axis;
	t_world_pnt camera_z_axis;
	t_camera camera;

	camera = vars_fdf->camera;
	calc_camera_z(&camera_z_axis, &camera.position, &camera.target);
	calc_camera_x(&camera_x_axis, &camera_z_axis, (camera.octant % 8 >= 4));
	cross(&camera_y_axis, &camera_z_axis, &camera_x_axis);
	camera_matrix[0][0] = camera_x_axis.x;
	camera_matrix[1][0] = camera_x_axis.y;
	camera_matrix[2][0] = camera_x_axis.z;
	camera_matrix[3][0] = -dot1x1(&camera_x_axis, &camera.position);
	camera_matrix[0][1] = camera_y_axis.x;
	camera_matrix[1][1] = camera_y_axis.y;
	camera_matrix[2][1] = camera_y_axis.z;
	camera_matrix[3][1] = -dot1x1(&camera_y_axis, &camera.position);
	camera_matrix[0][2] = camera_z_axis.x;
	camera_matrix[1][2] = camera_z_axis.y;
	camera_matrix[2][2] = camera_z_axis.z;
	camera_matrix[3][2] = -dot1x1(&camera_z_axis, &camera.position);
}

void	init_camera(t_vars_fdf *vars_fdf)
{
	init_position(vars_fdf);
	if (vars_fdf->p == iso) {
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
