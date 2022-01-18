/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:42:18 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 05:23:09 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input_Exit.h"
#include "../../includes/fdf.h"

void	del_frms(t_vars_fdf *vars_fdf)
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

int	exit_on_mlx_error(t_vars_fdf *vars_fdf, t_map *map)
{
	if (map)
		free_map(map);
	else
	{
		free_map(vars_fdf->map);
		free_view(vars_fdf);
	}
	free(vars_fdf);
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
	destroy_win(vars_fdf);
	free_view(vars_fdf);
	free_map(vars_fdf->map);
	exit(0);
}

void	destroy_win(t_vars_fdf *vars_fdf)
{
	del_frms(vars_fdf);
	mlx_destroy_window(vars_fdf->mlx, vars_fdf->win);
	mlx_loop_end(vars_fdf->mlx);
	free(vars_fdf->mlx);
	vars_fdf->win = NULL;
	vars_fdf->mlx = NULL;
}
