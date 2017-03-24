#include "visual.h"

void	del_tab(t_v *v, char **tab)
{
	int i;

	i = 0;
	while (i < v->map_s.y)
		free(tab[i++] - 4);
}
