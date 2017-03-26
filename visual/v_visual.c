#include "visual.h"
#include "fcntl.h"

void	v_get_player(t_v *v)
{
	char *line = NULL;

	ft_jump_lines(0, line, 6);
	get_next_line(0, &line);
	ft_printf("%c\n", *(line + 10));
	if (ft_atoi(line + 10) == 1 && ft_strstr(line, "agouby"))
		v->player = 'O';
	else
		v->player = 'X';
	ft_strdel(&line);
}

void	v_size_map(t_v *v)
{
	char *line = NULL;

	ft_jump_lines(0, line, 2);
	get_next_line(0, &line);
	v->map_s.y = ft_atoi(line + 8);
	v->map_s.x = ft_atoi(line + 8 + ft_count_digit(v->map_s.y, 10));
	ft_strdel(&line);
}

int		main()
{
	t_v v;

	char *line = NULL;
	//	init_v(&v);
	//	read_file(&v);
	create_win(&v);
//	reload(&v);
	int fd = open("lol", O_RDWR);
	v_get_player(&v);
	v_size_map(&v);
	get_square_size(&v);
	ft_printf("%d\n", v.sq_s);
	ft_jump_lines(0, line, 1);
	int i = 0;
	int y = 0;
	while (get_next_line(0, &line))
	{
		v.img = mlx_new_image(v.mlx, WIDTH, HEIGHT);	
		v.pixel_img = mlx_get_data_addr(v.img, &(v.bpp), &(v.s_line), &(v.ed));
		ft_dprintf(fd, "%s\n", line);
		ft_printf("y = %d\n", y);
		draw_square_line(&v, y, line);
		mlx_put_image_to_window(v.mlx, v.win, v.img, 0, 0);
		mlx_destroy_image(v.mlx, v.img);
		mlx_hook(v.win, 2, 2, key_hook, &v);
		mlx_loop(v.mlx);
	}
	ft_printf("%c\n", v.player);
	ft_printf("%d, %d\n", v.map_s.y, v.map_s.x);
	while (get_next_line(0, &line))
		ft_dprintf(fd, "%s\n" ,line);
	mlx_hook(v.win, 2, 2, key_hook, &v);
	mlx_loop(v.mlx);
	return (0);
}
