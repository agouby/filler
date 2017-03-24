#include "visual.h"

void	reload(t_v *v)
{
	v->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	v->pixel_img = mlx_get_data_addr(v->img, &(v->bpp), &(v->s_line), &(v->ed));
	draw_all_square(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	mlx_destroy_image(v->mlx, v->img);
}

void	create_win(t_v *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIDTH, HEIGHT, "Filler");
}
