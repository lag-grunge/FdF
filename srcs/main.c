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
#include "Input_Exit.h"
#include "draw.h"
#include "actions.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	*map;
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
	else if (get_map(fd, map) == -1)
	{
		write(1, "Error\n", 6);
		ret = map_read_error;
	}
	else
		graphics(map, argv[1]);
	free_map(map);
	return (ret);
}
