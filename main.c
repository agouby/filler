#include <fcntl.h>
#include "includes/ft_printf.h"

int main()
{
	char *str;
	int i;
	int fd;

	i = 0;
	fd = open("lol", O_RDWR);
	str = ft_strnew_set(500, '.');
	while (i < 500)
	{
		ft_dprintf(fd, "%s\n", str);
		i++;
	}
	return (0);
}
