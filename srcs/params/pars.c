/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:09:11 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 15:09:12 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "params.h"

void	get_win_sizes2(t_vars_fdf *vars_fdf)
{
	double	scale;
	double	winx;
	double	winy;

	winx = vars_fdf->screen_max.x - vars_fdf->screen_min.x;
	winy = vars_fdf->screen_max.y - vars_fdf->screen_min.y;
	scale = winx / winy;
	winx = sqrt(SQ_MAX / (MAX_POINTS + .0) * \
		vars_fdf->map->width * vars_fdf->map->length[0] * \
			32 * log2(vars_fdf->map->width * vars_fdf->map->length[0]) * scale);
	winy = max_size(SCREEN_HEIGHT, &winx, SCREEN_WIDTH, 1 / scale);
	vars_fdf->win_x = winx;
	vars_fdf->win_y = winy;
}
