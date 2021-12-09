/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:44:15 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 15:44:16 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"

enum e_errors {
	arg_error=1,
	file_error=2,
	map_read_error=3,
	mlx_error=4,
	win_error=5,
	malloc_error=6
};

enum e_proj {
	iso,
	psp
};

typedef unsigned int	t_uint;
typedef double			t_matrix[4][4];

typedef struct s_world_pnt {
	double	x;
	double	y;
	double	z;
}				t_world_pnt;

typedef struct s_view_pnt {
	double	x;
	double	y;
	int		color;
}				t_view_pnt;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

typedef struct s_map {
	unsigned int	**color;
	int				**altus;
	size_t			*length;
	size_t			width;
	t_world_pnt		**world;
	t_world_pnt		**world_cp;
	t_world_pnt		world_min;
	t_world_pnt		world_max;
	t_world_pnt		world_center;
	size_t			cur_i;
	size_t			cur_j;
}				t_map;

typedef struct s_camera {
	t_world_pnt	position;
	t_world_pnt	target;
	t_matrix	transformation;
	int			octant;
}				t_camera;

typedef struct s_states {
	int		r_pressed;
}				t_states;

typedef struct s_vars_fdf {
	void		*mlx;
	void		*win;
	int			win_x;
	int			win_y;
	t_data		**frms;
	t_map		*map;
	t_camera	camera;
	t_view_pnt	**view;
	t_view_pnt	**view_cp;
	enum e_proj p;
	double		tile;
	double		tile_cp;
	t_view_pnt 	trans;
	t_view_pnt	screen_min;
	t_view_pnt	screen_max;
	t_states	states;
}				t_vars_fdf;

#endif
