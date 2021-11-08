/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:27:09 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 14:27:11 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press_handle(int keycode, t_vars_fdf *vars_fdf)
{
	if (keycode == XK_ESC)
		destroy_fdf_and_exit(vars_fdf);
	if (keycode == XK_R)
		vars_fdf->states.r_pressed = !vars_fdf->states.r_pressed;
	if (keycode == XK_C)
		change_camera(vars_fdf);
	if (keycode == XK_I)
		zoom(vars_fdf, 1);
	if (keycode == XK_O)
		zoom(vars_fdf, 0);
	if (keycode == XK_DOWN)
		translate(vars_fdf, 0, -10);
	if (keycode == XK_UP)
		translate(vars_fdf, 0, 10);
	if (keycode == XK_LEFT)
		translate(vars_fdf, 10, 0);
	if (keycode == XK_RIGHT)
		translate(vars_fdf, -10, 0);
	return (0);
}
