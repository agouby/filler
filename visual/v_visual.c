#include "visual.h"
#include "fcntl.h"

int		v_loop(t_v *v)
{
	v->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);	
	v->pixel_img = mlx_get_data_addr(v->img, &(v->bpp), &(v->s_line), &(v->ed));
	t_coord i;

	i.y = 0;
	i.x = 0;
	while (i.y < HEIGHT)
	{
		i.x = 0;
		while (i.x < WIDTH)
		{
			draw_pixel(i.y, i.x, v, 0x031C1C);
			i.x++;
		}
		i.y++;
	}
	v_parse_file(v);
	v_draw_all_squares(v);
	v_draw_bk(v);
	v_draw_score(v, &v->p2);
	v_draw_score(v, &v->p1);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	v_draw_score_nb(v);
	mlx_destroy_image(v->mlx, v->img);
	return (0);
}

void	v_init_p(t_p *p)
{
	p->c = 0;
	p->nb_pos = 0;
}

void	v_init(t_v *v)
{
	v_init_p(&v->p1);
	v_init_p(&v->p2);
}

int		main()
{
	t_v v;
	t_p p;

	v_init(&v);
	v.p1.color = 0xFF2800;
	v.p2.color = 0x007BFF;
	v.bk_color = 0x303030;
	//	read_file(&v);
	create_win(&v);
//	reload(&v);
	mlx_hook(v.win, 2, 3, v_key_hook, &v);
	mlx_loop_hook(v.mlx, v_loop, (t_v *)&v);
	mlx_loop(v.mlx);
	return (0);
}
