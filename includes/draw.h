#ifndef FDF_DRAW_H
#define FDF_DRAW_H
# include "fdf.h"
# include "iter.h"
# define BORDER 0.99

int		gradient_color(int color1, int color2, size_t i, size_t steps);
void	draw_pnt_lines(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf);
int		render_frame(t_vars_fdf *vars_fdf);
void	init_frames(t_vars_fdf *vars_fdf);

#endif
