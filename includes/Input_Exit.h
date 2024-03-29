/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input_Exit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:27:10 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 18:27:42 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_EXIT_H
# define INPUT_EXIT_H
# include "fdf.h"
# define B16 "0123456789abcdef"
# define P16 "0x"
# define B10 "0123456789"
# define P10 "\0"

void	graphics(t_map *map, char *name);

void	init_map(t_map **m, int fd);
int		get_map(int fd, t_map *map);
void	init_view(t_view_pnt ***view, t_vars_fdf *vars_fdf);
void	init_world(t_world_pnt ***w, t_map *map);

void	v_alloc_exit(t_view_pnt ***view, t_map *map, size_t i);
void	w_alloc_exit(t_world_pnt ***world, t_map *map, size_t i);
void	free_split(char **split);
void	free_2d_array(void *arr_ptr, size_t rows);
void	free_view(t_vars_fdf *vars_fdf);
void	free_map(t_map *map);

void	del_frms(t_vars_fdf *vars_fdf);
int		destroy_fdf_and_exit(t_vars_fdf *vars_fdf);
void	destroy_win(t_vars_fdf *vars_fdf);
int		exit_on_mlx_error(t_vars_fdf *vars_fdf, t_map *map);
int		exit_on_win_error(t_vars_fdf *vars_fdf);

#endif
