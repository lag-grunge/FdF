/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 05:23:54 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 05:23:59 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include "actions.h"

int	translate(t_vars_fdf *vars_fdf, int x, int y)
{
	vars_fdf->trans.x += x;
	vars_fdf->trans.y += y;
	projection(vars_fdf);
	if (vars_fdf->states.r_pressed)
		return (1);
	iter_view(vars_fdf, minus_inplace_v, &vars_fdf->trans);
	render_frame(vars_fdf);
	return (0);
}
