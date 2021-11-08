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
# include "libft.h"

# define B16 "0123456789abcdef"
# define P16 "0x"
# define B10 "0123456789"
# define P10 "\0"
# define TIME_DELAY	10
# define BORDER 0.99
# define TILE_START 16
# define ZOOM_STEP 1.1
# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 2048
# endif
# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 1152
# endif
# ifdef MACOS
#  define XK_ESC 53
#  define XK_R 15
#  define XK_C 8
#  define XK_UP 126
#  define XK_DOWN 125
#  define XK_RIGHT 124
#  define XK_LEFT 123
#  define XK_I 34
#  define XK_O 31
# endif
# ifdef LINUX
#  define XK_ESC 65307
#  define XK_R 114
#  define XK_C 99
#  define XK_UP 65362
#  define XK_DOWN 65364
#  define XK_RIGHT 65363
#  define XK_LEFT 65361
#  define XK_I 105
#  define XK_O 111
# endif
# define KEYPRESS      2L
# define KEYPRESS_MASK 1L
# define DESTROYNOTIFY 17L
# define BUTTON_MASK 12L

enum e_errors {
	arg_error=1,
	file_error=2,
	map_read_error=3,
	mlx_error=4,
	win_error=5,
	malloc_error=6
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
	double		tile;
	double		tile_cp;
	t_view_pnt 	trans;
	t_view_pnt	screen_min;
	t_view_pnt	screen_max;
	t_states	states;
}				t_vars_fdf;

int		get_map(int fd, t_map *map);
void	init_map(t_map *map, int fd);
void	init_camera_positon(t_world_pnt *camera_position, t_vars_fdf *vars_fdf);
void	free_2d_array(void *arr_ptr, size_t rows);
void	free_map(t_map *map);
void	free_view(t_vars_fdf *vars_fdf);

int		destroy_fdf_and_exit(t_vars_fdf *vars_fdf);
int		exit_on_mlx_error(t_map	*map);
int		exit_on_win_error(t_vars_fdf *vars_fdf);

void	model_world(t_map *map);
void	comp_view_pnt(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf);

void	projection(t_vars_fdf *vars_fdf);

void	minus_inplace(t_world_pnt *a, t_world_pnt *b);
void	plus_inplace(t_world_pnt *a, t_world_pnt *b);
void	minus_inplace_v(t_view_pnt *a, t_view_pnt *b);
void	plus_inplace_v(t_view_pnt *a, t_view_pnt *b);
void	multi_inplace_v(t_view_pnt *a, double *mult);
void	div_inplace_v(t_view_pnt *a, double *div);

int		find_max2i(int a, int b);
double	max_size(double maxa, double *b, double maxb, double scale);

void	cross(t_world_pnt *cross, t_world_pnt *a, t_world_pnt *b);
void	normalization(t_world_pnt *a);
double	dest_square(t_world_pnt a);

void	find_max_min_world(t_world_pnt *w_pnt, t_map *map);
void	find_max_min_view(t_world_pnt *view_pnt, t_vars_fdf *vars_fdf);
double	dot1x1(t_world_pnt *a, t_world_pnt *b);
void	dot1x2(t_world_pnt *a, t_matrix mat4x4);
void	rotation_z(t_world_pnt *w);

int		change_camera(t_vars_fdf *vars_fdf);

void	init_camera(t_vars_fdf *vars_fdf);
void	init_screen(t_vars_fdf *vars_fdf);

int		translate(t_vars_fdf *vars_fdf, int x, int y);
int		zoom(t_vars_fdf *vars_fdf, int in_out);

void	init_camera(t_vars_fdf *vars_fdf);

void	dda_line_put(t_data	*data, t_view_pnt *a, t_view_pnt *b);
void	my_pixel_put(t_data	*data, t_view_pnt *view_pnt, int color);
void	draw_pnt_lines(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf);

void	get_win_sizes(t_vars_fdf *vars_fdf);
double	calc_tile(t_vars_fdf *vars_fdf, double start_tile);

int		rotate(t_vars_fdf *vars_fdf);
int		render_frame(t_vars_fdf *vars_fdf);
void	init_frames(t_vars_fdf *vars_fdf);

int		key_press_handle(int keycode, t_vars_fdf *vars_fdf);
void	free_map(t_map *map);
void	free_split(char **split);

void	init_view(t_view_pnt ***view, t_vars_fdf *vars_fdf);
void	init_world(t_world_pnt ***w, t_map *map);

void	iter_world(t_map *map, void (*func)(), void *par);
void	iter_view(t_vars_fdf *vars_fdf, void (*func)(), void *par);

void	copy_view_pnt(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf);
void	reset_view_pnt(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf);
void	copy_wrld_point(t_world_pnt *w_pnt, t_map *map);
void	reset_wrld_point(t_world_pnt *w_pnt, t_map *map);

int		gradient_color(int color1, int color2, size_t i, size_t steps);

#endif
