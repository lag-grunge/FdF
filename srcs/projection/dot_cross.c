/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:43:26 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 13:43:28 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

double	dest_square(t_world_pnt a)
{
	double	a_len;

	a_len = a.x * a.x;
	a_len += a.y * a.y;
	a_len += a.z * a.z;
	return (a_len);
}

void	normalization(t_world_pnt *a)
{
	double	a_len;

	a_len = sqrt(dest_square(*a));
	if (a_len)
	{
		a->x /= a_len;
		a->y /= a_len;
		a->z /= a_len;
	}
}

void	cross(t_world_pnt *cross, t_world_pnt *a, t_world_pnt *b)
{
	cross->x = a->y * b->z;
	cross->x -= b->y * a->z;
	cross->y = b->x * a->z;
	cross->y -= a->x * b->z;
	cross->z = a->x * b->y;
	cross->z -= b->x * a->y;
}

double	dot1x1(t_world_pnt *a, t_world_pnt *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

void	dot1x2(t_world_pnt *a, t_matrix mat4x4)
{
	t_world_pnt	tmp;

	tmp.x = a->x;
	tmp.y = a->y;
	tmp.z = a->z;
	a->x = tmp.x * mat4x4[0][0];
	a->x += tmp.y * mat4x4[1][0];
	a->x += tmp.z * mat4x4[2][0];
	a->x += 1 * mat4x4[3][0];
	a->y = tmp.x * mat4x4[0][1];
	a->y += tmp.y * mat4x4[1][1];
	a->y += tmp.z * mat4x4[2][1];
	a->y += 1 * mat4x4[3][1];
	a->z = tmp.x * mat4x4[0][2];
	a->z += tmp.y * mat4x4[1][2];
	a->z += tmp.z * mat4x4[2][2];
	a->z += 1 * mat4x4[3][2];
}
