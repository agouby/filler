#include "libft.h"

void	ft_swap_tab(int **a, int **b)
{
	int *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
