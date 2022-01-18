/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:29:11 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 18:29:26 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "fdf.h"
# include "iter.h"
# define BORDER 0.99

int		gradient_color(int color1, int color2, size_t i, size_t steps);
void	draw_pnt_lines(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf);
int		render_frame(t_vars_fdf *vars_fdf);
void	init_frames(t_vars_fdf *vars_fdf);

#endif
