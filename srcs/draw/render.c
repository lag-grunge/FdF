/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:26:07 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 16:26:09 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	create_image(t_vars_fdf *vars_fdf, t_data *data)
{
	int	*bpp;
	int	*endian;
	int	*line_len;

	data->img = mlx_new_image(vars_fdf->mlx, vars_fdf->win_x, vars_fdf->win_y);
	bpp = &data->bpp;
	endian = &data->endian;
	line_len = &data->line_len;
	data->addr = mlx_get_data_addr(data->img, bpp, line_len, endian);
}

static void copy_frame(t_data *cur_frame, t_data *next_frame)
{
	cur_frame->img = next_frame->img;
	cur_frame->addr = next_frame->addr;
	cur_frame->bpp = next_frame->bpp;
	cur_frame->line_len = next_frame->line_len;
	cur_frame->endian = next_frame->endian;
}

void	init_frames(t_vars_fdf *vars_fdf)
{
	vars_fdf->frms = (t_data **)malloc(sizeof(t_data *) * 2);
	vars_fdf->frms[0] = (t_data *)malloc(sizeof(t_data));
	vars_fdf->frms[1] = (t_data *)malloc(sizeof(t_data));
	vars_fdf->frms[0]->img = NULL;
	vars_fdf->frms[1]->img = NULL;
}

int	render_frame(t_vars_fdf *vars_fdf)
{
	t_data	*next_frame;
	t_data	*cur_frame;

	cur_frame = vars_fdf->frms[0];
	next_frame = vars_fdf->frms[1];
	create_image(vars_fdf, next_frame);
	iter_view(vars_fdf, draw_pnt_lines, vars_fdf);
	mlx_put_image_to_window(vars_fdf->mlx, vars_fdf->win,\
		next_frame->img, 0, 0);
	if (cur_frame->img)
	{
		if (cur_frame->img)
			mlx_destroy_image(vars_fdf->mlx, cur_frame->img);
		cur_frame->img = NULL;
	}
	copy_frame(cur_frame, next_frame);
	next_frame->img = NULL;
	return (0);
}
