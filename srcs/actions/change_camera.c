/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:38:56 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 04:34:51 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

int	change_camera(t_vars_fdf *vars_fdf)
{
	vars_fdf->camera.octant++;
	init_camera(vars_fdf, 0);
	projection(vars_fdf);
	iter_view(vars_fdf, minus_inplace_v, &vars_fdf->trans);
	render_frame(vars_fdf);
	return (0);
}
