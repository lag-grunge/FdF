/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:48:40 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 15:48:42 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	my_pixel_put(t_data	*data, t_view_pnt *view_pnt, int color)
{
	char	*dst;
	int		x;
	int		y;

	x = round(view_pnt->x);
	y = round(view_pnt->y);
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static size_t	calc_step(double dx, double dy)
{
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	if (dx < dy)
		return (dy);
	return (dx);
}

static void	dda_line_put(t_data	*data, t_view_pnt *a, t_view_pnt *b)
{
	double	dx;
	double	dy;
	size_t	step;
	size_t	i;

	dx = b->x - a->x;
	dy = b->y - a->y;
	step = calc_step(dx, dy);
	dx = dx / step;
	dy = dy / step;
	i = 0;
	while (i <= step)
	{
		my_pixel_put(data, a, gradient_color(a->color, b->color, i, step));
		a->x += dx;
		a->y += dy;
		i++;
	}
}

static int	border(t_view_pnt *v1, t_view_pnt *v2, t_vars_fdf *vars_fdf)
{
	double	winx;
	double	winy;

	winx = vars_fdf->win_x;
	winy = vars_fdf->win_y;
	if (v2->y < 0 || v2->x < 0 || v1->x < 0 || v1->y < 0)
		return (0);
	if (v1->x >= winx)
		return (0);
	if (v2->x >= winx)
		return (0);
	if (v1->y >= winy)
		return (0);
	if (v2->y >= winy)
		return (0);
	return (1);
}

void	draw_pnt_lines(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf)
{
	t_map		*map;
	t_data		*data;
	t_view_pnt	**view;
	size_t		i;
	size_t		j;

	map = vars_fdf->map;
	view = vars_fdf->view;
	i = map->cur_i;
	j = map->cur_j;
	data = vars_fdf->frms[1];
	if (j < map->length[i] - 1)
		if (border(view_pnt, &view[i][j + 1], vars_fdf))
			dda_line_put(data, view_pnt, &view[i][j + 1]);
	if (i < map->width - 1 && j < map->length[i + 1] - 1)
		if (border(view_pnt, &view[i + 1][j + 1], vars_fdf))
			dda_line_put(data, view_pnt, &view[i + 1][j + 1]);
}
