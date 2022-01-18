/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:19:27 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 15:49:33 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input_Exit.h"
#include "../../includes/fdf.h"

size_t	get_map_width(int fd)
{
	size_t	nl_counts;
	char	ch;

	nl_counts = 0;
	while (read(fd, &ch, 1))
	{
		if (ch == 10)
			nl_counts++;
	}
	if (ch == 10)
		return (nl_counts);
	return (nl_counts + 1);
}

void	init_map(t_map **m, int fd)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		exit(malloc_error);
	map->width = get_map_width(fd);
	map->length = (size_t *)ft_calloc(sizeof(size_t), map->width);
	if (!map->length)
		exit(malloc_error);
	map->altus = (int **)ft_calloc(sizeof(int *), map->width);
	if (!map->altus)
		exit(malloc_error);
	map->color = (t_uint **)ft_calloc(sizeof(t_uint *), map->width);
	if (!map->color)
		exit(malloc_error);
	map->world = NULL;
	map->world_cp = NULL;
	*m = map;
}

static size_t	check_line(char **sp_line, size_t i, t_map *map)
{
	char	**sp_val;
	int		ovflw;

	map->length[i] = 0;
	ovflw = 0;
	if (!sp_line)
		return (0);
	while (sp_line[map->length[i]])
	{
		sp_val = ft_split(sp_line[map->length[i]], ',');
		ft_atoi_base(sp_val[0], B10, P10, &ovflw);
		if (ovflw)
			return (0);
		if (sp_val[1])
		{
			ft_atoi_base(sp_val[1], B16, P16, &ovflw);
			if (ovflw)
				return (0);
		}
		map->length[i]++;
		free_split(sp_val);
	}
	return (map->length[i]);
}

static int	get_map_line(char **sp_line, size_t i, t_map *map)
{
	size_t	j;
	char	**sp_val;

	map->length[i] = check_line(sp_line, i, map);
	if (!map->length[i])
		return (-1);
	map->altus[i] = (int *)ft_calloc(sizeof(int), map->length[i]);
	map->color[i] = (t_uint *)ft_calloc(sizeof(t_uint), map->length[i]);
	if (!map->altus[i])
		return (-1);
	j = 0;
	while (j < map->length[i])
	{
		sp_val = ft_split(sp_line[j], ',');
		map->altus[i][j] = ft_atoi(sp_val[0]);
		map->color[i][j] = 0xFFFFFF;
		if (sp_val[1])
			map->color[i][j] = ft_usgn_atoi_base(sp_val[1], B16, P16, NULL);
		j++;
		free_split(sp_val);
	}
	return (1);
}

int	get_map(int fd, t_map *map)
{
	char	*line;
	char	**sp_line;
	size_t	i;
	int		ret;

	line = 0;
	i = 0;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret != 1)
			break ;
		sp_line = ft_split(line, ' ');
		ret = get_map_line(sp_line, i, map);
		i++;
		free_split(sp_line);
		free(line);
		line = 0;
	}
	return (ret);
}
