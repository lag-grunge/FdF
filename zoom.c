#include "fdf.h"

int zoom(t_vars_fdf *vars_fdf, int in_out)
{
	static double zoom = 1.;

	if (in_out)
		zoom /= ZOOM_STEP;
	else
		zoom *= ZOOM_STEP;
	vars_fdf->tile = zoom * vars_fdf->tile_cp;
	projection(vars_fdf);
	iter_view(vars_fdf, minus_inplace_v, &vars_fdf->trans);
	render_frame(vars_fdf);
	return (0);
}