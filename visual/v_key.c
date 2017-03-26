#include "visual.h"

int		key_hook(int key, t_v *v)
{
	if (key == ESC_M)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	return (0);
}
