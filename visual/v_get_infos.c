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
