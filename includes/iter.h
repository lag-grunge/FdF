/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:24:13 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 18:24:36 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H
# include "fdf.h"

void	copy_view_pnt(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf);
void	reset_view_pnt(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf);
void	copy_wrld_point(t_world_pnt *w_pnt, t_map *map);
void	reset_wrld_point(t_world_pnt *w_pnt, t_map *map);
void	find_max_min_world(t_world_pnt *w_pnt, t_map *map);
void	find_max_min_view(t_world_pnt *view_pnt, t_vars_fdf *vars_fdf);
void	iter_world(t_map *map, void (*func)(), void *par);
void	iter_view(t_vars_fdf *vars_fdf, void (*func)(), void *par);
void	minus_inplace(t_world_pnt *a, t_world_pnt *b);
void	plus_inplace(t_world_pnt *a, t_world_pnt *b);
void	minus_inplace_v(t_view_pnt *a, t_view_pnt *b);
void	plus_inplace_v(t_view_pnt *a, t_view_pnt *b);
void	multi_inplace_v(t_view_pnt *a, double *mult);
void	printiter(t_world_pnt *w, void *args);
void	printviter(t_view_pnt *v, void *args);

#endif
