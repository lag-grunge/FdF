/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_minus_inplace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:45:01 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 15:45:02 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"

void	minus_inplace(t_world_pnt *a, t_world_pnt *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
}

void	plus_inplace(t_world_pnt *a, t_world_pnt *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
}

void	minus_inplace_v(t_view_pnt *a, t_view_pnt *b)
{
	a->x -= b->x;
	a->y -= b->y;
}

void	plus_inplace_v(t_view_pnt *a, t_view_pnt *b)
{
	a->x += b->x;
	a->y += b->y;
}

void	multi_inplace_v(t_view_pnt *a, double *mult)
{
	a->x *= *mult;
	a->y *= *mult;
}
