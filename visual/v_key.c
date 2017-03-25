#include "visual.h"

int		key_hook(int key, t_v *v)
{
	if (key == ESC_M)
	{
		int i = 0;
		while (v->lst)
		{
			i = 0;
			while (i < v->map_s.y)
				free(((char **)v->lst->content)[i++] - 4);
			free(((char **)v->lst->content));
			free(v->lst);
			v->lst = v->lst->next;
		}
/*		if ((v->fd = open("visual.txt", O_TRUNC) == -1))
			ft_print_error("RIP");
		close(v->fd);
*/		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	if (key == SP_M)
	{
		if (v->lst->next)
			v->lst = v->lst->next;
		reload(v);
	}
	return (0);
}
