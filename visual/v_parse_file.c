#include "visual.h"

void	store_in_list(t_v *v, char *line)
{
	int i;
	char **tab;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (v->map_s.y + 1));
	while (get_next_line(v->fd, &line))
	{
		tab[i] = line + 4;
		i++;
		if (i == v->map_s.y)
		{
			tab[i] = NULL;
			ft_lstadd_b(&v->lst, ft_lstnew(tab, sizeof(tab) * v->map_s.y));
			i = 0;
			get_next_line(v->fd, &line);
			free(line);
		}
	}
	free(tab);
	free(line);
}

void	read_file(t_v *v)
{
	char	*line;

	line = NULL;
	if ((v->fd = open("visual.txt", O_RDONLY)) == -1)
		ft_print_error("Open failed on visual.cfg");
	get_infos(v->fd, v, line);
	store_in_list(v, line);
}
