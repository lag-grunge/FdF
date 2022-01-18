#ifndef FDF_PROJECTION_H
#define FDF_PROJECTION_H
# include "fdf.h"
# include "iter.h"
#include "params.h"
# include "Input_Exit.h"

void	projection(t_vars_fdf *vars_fdf);
void	cross(t_world_pnt *cross, t_world_pnt *a, t_world_pnt *b);
void	normalization(t_world_pnt *a);
double	dest_square(t_world_pnt a);
double	dot1x1(t_world_pnt *a, t_world_pnt *b);
void	dot1x2(t_world_pnt *a, t_matrix mat4x4);
void	dot2x2(t_matrix res, t_matrix mat1, t_matrix mat2);
void	get_matrix(t_vars_fdf *vars_fdf, double camera_matrix[4][4]);
void init_camera(t_vars_fdf *vars_fdf, int change_proj);
void	model_world(t_map *map);
void	comp_view_pnt(t_view_pnt *view_pnt, t_vars_fdf *vars_fdf);

#endif
