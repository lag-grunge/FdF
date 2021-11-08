/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:42:18 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 13:42:19 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	del_frms(t_vars_fdf *vars_fdf)
{
	if (vars_fdf->frms[0])
	{
		if (vars_fdf->frms[0]->img)
			mlx_destroy_image(vars_fdf->mlx, vars_fdf->frms[0]->img);
		free(vars_fdf->frms[0]);
	}
	if (vars_fdf->frms[1])
	{
		if (vars_fdf->frms[1]->img)
			mlx_destroy_image(vars_fdf->mlx, vars_fdf->frms[1]->img);
		free(vars_fdf->frms[1]);
	}
	free(vars_fdf->frms);
}

int	exit_on_mlx_error(t_map	*map)
{
	free_map(map);
	exit(mlx_error);
}

int	exit_on_win_error(t_vars_fdf *vars_fdf)
{
	free_view(vars_fdf);
	free_map(vars_fdf->map);
	exit(win_error);
}

int	destroy_fdf_and_exit(t_vars_fdf *vars_fdf)
{
	del_frms(vars_fdf);
	mlx_destroy_window(vars_fdf->mlx, vars_fdf->win);
	mlx_loop_end(vars_fdf->mlx);
	free(vars_fdf->mlx);
	vars_fdf->win = NULL;
	vars_fdf->mlx = NULL;
	free_view(vars_fdf);
	free_map(vars_fdf->map);
	exit(0);
}
