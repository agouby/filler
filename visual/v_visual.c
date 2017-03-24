#include "visual.h"

int		main()
{
	t_v v;

	init_v(&v);
	read_file(&v);
	create_win(&v);
	reload(&v);
	mlx_hook(v.win, 2, 3, key_hook, &v);
	mlx_loop(v.mlx);
	return (0);
}
