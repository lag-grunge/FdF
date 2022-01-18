#ifndef FDF_PARAMS_H
#define FDF_PARAMS_H
# include "fdf.h"
# include "draw.h"

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 2048
# endif
# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 1152
# endif
# define MIN_WIN_SIZE 200
# define TILE_START 16

void	init_window(t_vars_fdf *vars, char *name);
void	get_win_sizes(t_vars_fdf *vars_fdf);
void	get_win_sizes2(t_vars_fdf *vars_fdf);
double	calc_tile(t_vars_fdf *vars_fdf, double start_tile);
int		find_max2i(int a, int b);
double	max_size(double maxa, double *b, double maxb, double scale);

#endif
