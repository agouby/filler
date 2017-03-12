/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:13:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/12 07:12:31 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_player(char *line)
{
	if (ft_strstr(line, "agouby"))
		return (1);
	return (2);	
}

void	get_size(char *line, int *x, int *y)
{
	while (!ft_isdigit(*line))
		line++;
	*y = ft_atoi(line);
	line += ft_count_digit(*x, 10);
	*x = ft_atoi(line);
}

char	*fill_line_in_map(int fd)
{
	char	*line;

	get_next_line(fd, &line);
	line = ft_strsub(line, 4, ft_strlen(line));
	return (line);

}

char	**create_map(int fd, int y)
{
	char **map;
	int	y_tmp;

	map = (char **)malloc(sizeof(char *) * y);
	y_tmp = 0;
	while (y_tmp < y)
	{
		map[y_tmp] = fill_line_in_map(fd);
		y_tmp++;
	}
	map[y_tmp] = "\0";
//	ft_printf("%s\n", map[4]);
	return (map);
}

void	print_map(char **map, int y)
{
	int i;

	i = 0;
	while (i < y)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	filler(void)
{
	int	fd;
	int	i;
	int x;
	int y;
	char *line;
	char **map;

	fd = open("test/map00", O_RDONLY);
	i = 0;
	while (i++ < 7)
		get_next_line(fd, &line);
//	ft_printf("Je suis le joueur : %d\n", get_player(line));
	ft_strdel(&line);
	i = 0;
	while (i++ < 3)
		get_next_line(fd, &line);
	get_size(line, &x, &y);
	ft_strdel(&line);
//	ft_printf("La map a une taille de : %d, %d\n", x, y);
	get_next_line(fd, &line);
	map = create_map(fd, y);
	print_map(map, y);
	ft_strdel(&line);
}

int		main(void)
{
	filler();
	return (0);
};
