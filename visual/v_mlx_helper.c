#include "visual.h"

void	create_win(t_v *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIDTH, HEIGHT, "Filler");
}
