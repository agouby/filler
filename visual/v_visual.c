#include "visual.h"
#include "fcntl.h"

int		v_loop(t_v *v)
{
	v->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);	
	v->pixel_img = mlx_get_data_addr(v->img, &(v->bpp), &(v->s_line), &(v->ed));
	v_parse_file(v);
	v_draw_all_squares(v);
	v_draw_score_bk(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	mlx_destroy_image(v->mlx, v->img);
	return (0);
}

void	v_init(t_v *v)
{
	v->map = NULL;
}

int		main()
{
	t_v v;

	v_init(&v);
	//	read_file(&v);
	create_win(&v);
//	reload(&v);
	
	mlx_hook(v.win, 2, 2, v_key_hook, &v);
	mlx_loop_hook(v.mlx, v_loop, &v);
	mlx_loop(v.mlx);
	return (0);
}
