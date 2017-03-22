#include "visual.h"

void	get_infos(int fd, t_v *v, char *line)
{
	get_next_line(fd, &line);
	v->p = line[0];
	free(line);
	get_next_line(fd, &line);
	v->map_s.y = ft_atoi(line);
	free(line);
	get_next_line(fd, &line);
	v->map_s.x = ft_atoi(line);
	free(line);
}

char	**create_tab(int fd, t_v *v, char *line, char **tab)
{
	int i;

	i = 0;
	while (i < v->map_s.y && get_next_line(fd, &line))
	{
		ft_printf("%s\n", tab[i]);
		tab[i++] = line;
	}
	tab[i] = NULL;
	return (tab);
}

void	read_file(t_v *v)
{
	int		fd;
	char	*line;
	t_list	*lst;
	char	**tab;

	line = NULL;
	lst = ft_lstnew(NULL, 0);
	if ((fd = open("visual.txt", O_RDONLY)) == -1)
		ft_print_error("Open failed on visual.cfg");
	get_infos(fd, v, line);
	tab = (char **)malloc(sizeof(char *) * (v->map_s.y + 1));
	tab = create_tab(fd, v, line, tab);
}

void	create_win(t_v *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIDTH, HEIGHT, "Filler");
}

int		key_hook(int key, t_v *v)
{
	if (key == ESC)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	return (0);
}

int		main()
{
	t_v v;
	
	read_file(&v);
	create_win(&v);
	mlx_hook(v.win, 2, 3, key_hook, (t_v *)&v);
	mlx_loop(v.mlx);
	return (0);
}
