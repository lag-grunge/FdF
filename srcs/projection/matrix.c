/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 06:05:48 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 06:10:02 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

static void	adj3x3(double *det, double inverse_matrix[3][3], \
		double camera_matrix[4][4])
{
	int	i;
	int	j;

	*det = 0;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			inverse_matrix[i][j] = camera_matrix[(i + 1) % 3][(j + 1) % 3] * \
						camera_matrix[(i + 2) % 3][(j + 2) % 3];
			inverse_matrix[i][j] -= camera_matrix[(i + 1) % 3][(j + 2) % 3] * \
									camera_matrix[(i + 2) % 3][(j + 1) % 3];
			if (i == 0)
				*det += camera_matrix[i][j] * inverse_matrix[i][j];
			j++;
		}
		i++;
	}
}

static void	inv3x3(double camera_matrix[4][4])
{
	double	inverse_matrix[3][3];
	double	det;
	int		i;
	int		j;

	adj3x3(&det, inverse_matrix, camera_matrix);
	if (!det)
		return ;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			camera_matrix[i][j] = inverse_matrix[j][i] / det;
			j++;
		}
		i++;
	}
}

static void	calc_camera_z(t_world_pnt *c_z, t_world_pnt *c, t_world_pnt *t)
{
	c_z->x = c->x;
	c_z->y = c->y;
	c_z->z = c->z;
	minus_inplace(c_z, t);
	normalization(c_z);
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

void	get_matrix(t_vars_fdf *vars_fdf, double camera_matrix[4][4])
{
	t_world_pnt	camera_x_axis;
	t_world_pnt	camera_y_axis;
	t_world_pnt	camera_z_axis;
	t_camera	camera;

	camera = vars_fdf->camera;
	calc_camera_z(&camera_z_axis, &camera.position, &camera.target);
	calc_camera_x(&camera_x_axis, &camera_z_axis, (camera.octant % 8 >= 4));
	cross(&camera_y_axis, &camera_x_axis, &camera_z_axis);
	camera_matrix[0][0] = camera_x_axis.x;
	camera_matrix[0][1] = camera_x_axis.y;
	camera_matrix[0][2] = camera_x_axis.z;
	camera_matrix[1][0] = camera_y_axis.x;
	camera_matrix[1][1] = camera_y_axis.y;
	camera_matrix[1][2] = camera_y_axis.z;
	camera_matrix[2][0] = camera_z_axis.x;
	camera_matrix[2][1] = camera_z_axis.y;
	camera_matrix[2][2] = camera_z_axis.z;
	camera_matrix[3][0] = -dot1x1(&camera_x_axis, &camera.position);
	camera_matrix[3][1] = -dot1x1(&camera_y_axis, &camera.position);
	camera_matrix[3][2] = -dot1x1(&camera_z_axis, &camera.position);
	inv3x3(camera_matrix);
}
