/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 07:18:47 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 07:19:27 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "params.h"
#include "Input_Exit.h"
#include "actions.h"

void	init_window(t_vars_fdf *vars, char *name)
{
	init_camera(vars, 0);
	projection(vars);
	iter_view(vars, copy_view_pnt, vars);
	get_win_sizes(vars);
	vars->p = psp;
	init_camera(vars, 1);
	projection(vars);
	vars->p = iso;
	init_camera(vars, 1);
	projection(vars);
	vars->win = mlx_new_window(vars->mlx, vars->win_x, vars->win_y, name);
	if (!vars->win)
		exit_on_win_error(vars);
}

static void	init_vars(t_vars_fdf *vars_fdf, t_map *map)
{
	vars_fdf->states.r_pressed = 0;
	vars_fdf->trans.x = 0;
	vars_fdf->trans.y = 0;
	if (!map)
		return ;
	vars_fdf->mlx = mlx_init();
	if (!vars_fdf->mlx)
		exit_on_mlx_error(vars_fdf, map);
	vars_fdf->win_x = 0;
	vars_fdf->win_y = 0;
	vars_fdf->camera.octant = 0;
	vars_fdf->win = NULL;
	vars_fdf->frms = NULL;
	vars_fdf->map = map;
	vars_fdf->p = iso;
	init_view(&vars_fdf->view, vars_fdf);
	init_view(&vars_fdf->view_cp, vars_fdf);
}

void	graphics(t_map *map, char *name)
{
	static t_vars_fdf	*vars;

	if (!vars || map)
	{
		vars = (t_vars_fdf *) malloc(sizeof(t_vars_fdf));
		model_world(map);
		init_vars(vars, map);
		init_window(vars, name);
		init_frames(vars);
	}
	else
	{
		init_vars(vars, NULL);
		init_camera(vars, 1);
		projection(vars);
	}
	render_frame(vars);
	if (!map)
		return ;
	mlx_loop_hook(vars->mlx, rotate, vars);
	mlx_hook(vars->win, KEYPRESS, KEYPRESS_MASK, key_press_handle, vars);
	mlx_hook(vars->win, DESTROYNOTIFY, BUTTON_MASK, destroy_fdf_and_exit, vars);
	mlx_loop(vars->mlx);
}
