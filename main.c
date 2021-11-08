/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:35:17 by sdalton           #+#    #+#             */
/*   Updated: 2021/11/08 04:02:23 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_states(t_vars_fdf *vars_fdf)
{
	vars_fdf->states.r_pressed = 0;
	vars_fdf->camera.octant = 0;
	vars_fdf->trans.x = 0;
	vars_fdf->trans.y = 0;
	vars_fdf->view = NULL;
	vars_fdf->view_cp = NULL;
}

static void	graphics(t_map *map, char *name)
{
	t_vars_fdf	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		exit_on_mlx_error(map);
	model_world(map);
	vars.map = map;
	init_states(&vars);
	init_camera(&vars);
	projection(&vars);
	get_win_sizes(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.win_x, vars.win_y, name);
	if (!vars.win)
		exit_on_win_error(&vars);
	init_frames(&vars);
	render_frame(&vars);
	mlx_loop_hook(vars.mlx, rotate, &vars);
	mlx_hook(vars.win, KEYPRESS, KEYPRESS_MASK, key_press_handle, &vars);
	mlx_hook(vars.win, DESTROYNOTIFY, BUTTON_MASK, destroy_fdf_and_exit, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	map;
	int		ret;

	if (argc != 2)
		return (arg_error);
	ret = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (file_error);
	init_map(&map, fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ret = file_error;
	else if (get_map(fd, &map) == -1)
	{
		write(1, "Error\n", 6);
		ret = map_read_error;
	}
	else
		graphics(&map, argv[1]);
	free_map(&map);
	return (ret);
}