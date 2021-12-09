#include "iter.h"

void printiter(t_world_pnt *w, void *args)
{
	t_map *map;

	map = args;
	printf("i = %zu j = %zu - (x = %f, y = %f, z = %f)\n", map->cur_i, map->cur_j, w->x, w->y, w->z);
}

void printviter(t_view_pnt *v, void *args)
{
	t_map *map;
	t_vars_fdf *vars;

	vars = args;
	map = vars->map;
	printf("i = %zu j = %zu - (x = %f, y = %f)\n", map->cur_i, map->cur_j, v->x, v->y);
}
