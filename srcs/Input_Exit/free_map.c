/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:07:31 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 14:07:33 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input_Exit.h"

void	free_split(char **split)
{
	char	**tmp;

	tmp = split;
	if (!split)
		return ;
	while (*split)
	{
		free(*split);
		split++;
	}
	free(tmp);
}

void	free_2d_array(void *arr_ptr, size_t rows)
{
	size_t	i;
	void	**array;

	i = 0;
	array = (void **)arr_ptr;
	while (i < rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_map(t_map *map)
{
	if (map->color)
	{
		free_2d_array(map->color, map->width);
		map->color = NULL;
	}
	if (map->altus)
	{
		free_2d_array(map->altus, map->width);
		map->altus = NULL;
	}
	if (map->length)
	{
		free(map->length);
		map->length = NULL;
	}
	if (map->world)
	{
		free_2d_array(map->world, map->width);
		map->world = NULL;
	}
	if (map->world_cp)
	{
		free_2d_array(map->world_cp, map->width);
		map->world_cp = NULL;
	}
}

void	free_view(t_vars_fdf *vars_fdf)
{
	if (vars_fdf->view)
	{
		free_2d_array(vars_fdf->view, vars_fdf->map->width);
		vars_fdf->view = NULL;
	}
	if (vars_fdf->view_cp)
	{
		free_2d_array(vars_fdf->view_cp, vars_fdf->map->width);
		vars_fdf->view_cp = NULL;
	}
}
