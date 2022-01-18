/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 05:24:18 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 05:24:55 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

int	zoom(t_vars_fdf *vars_fdf, int in_out)
{
	static double	zoom;

	if (!zoom)
		zoom = vars_fdf->tile / (vars_fdf->tile_cp + .0);
	if (in_out && zoom * ZOOM_STEP < 32.0)
		zoom *= ZOOM_STEP;
	else if (!in_out && zoom / ZOOM_STEP > 0.05)
		zoom /= ZOOM_STEP;
	vars_fdf->tile = zoom * vars_fdf->tile_cp;
	if (vars_fdf->p == psp)
		init_camera(vars_fdf, 1);
	projection(vars_fdf);
	iter_view(vars_fdf, minus_inplace_v, &vars_fdf->trans);
	render_frame(vars_fdf);
	return (0);
}
