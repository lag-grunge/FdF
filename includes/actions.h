#ifndef FDF_ACTIONS_H
#define FDF_ACTIONS_H
# include "fdf.h"
# include "Input_Exit.h"
# include "projection.h"
# include "params.h"
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
#  define XK_P 112
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
# define ZOOM_STEP 1.1
# define TIME_DELAY	10

int		key_press_handle(int keycode, t_vars_fdf *vars_fdf);
int		rotate(t_vars_fdf *vars_fdf);
int		translate(t_vars_fdf *vars_fdf, int x, int y);
int		zoom(t_vars_fdf *vars_fdf, int in_out);
int		change_camera(t_vars_fdf *vars_fdf);

#endif
