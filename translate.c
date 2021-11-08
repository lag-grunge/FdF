#include "fdf.h"

int translate(t_vars_fdf *vars_fdf, int x, int y)
{
	vars_fdf->trans.x += x;
	vars_fdf->trans.y += y;
	projection(vars_fdf);
	iter_view(vars_fdf, minus_inplace_v, &vars_fdf->trans);
	render_frame(vars_fdf);
	return (0);
}