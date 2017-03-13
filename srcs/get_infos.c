/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 02:46:26 by agouby            #+#    #+#             */
/*   Updated: 2017/03/13 03:21:01 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_player(int fd, char *line)
{
	size_t	i;

	i = 0;
	while (i++ < 6)
	{
		get_next_line(fd, &line);
		ft_strdel(&line);
	}
	get_next_line(fd, &line);
	if (ft_strstr(line, "agouby"))
	{
		ft_strdel(&line);
		return (1);
	}
	ft_strdel(&line);
	return (2);	
}

void	get_size(char *line, size_t *x, size_t *y)
{
	*y = ft_atoi(line + 8);
	*x = ft_atoi(line + 8 + ft_count_digit(*x, 10));
	ft_strdel(&line);
}

char	**create_map(int fd, size_t y_s)
{
	char	**map;
	size_t	y_tmp;

	if (!(map = (char **)malloc(sizeof(char *) * y_s)))
		ft_print_error("Memory allocation failed.");
	y_tmp = 0;
	while (y_tmp < y_s)
		get_next_line(fd, &map[y_tmp++]);
	map[y_s] = NULL;
	return (map);
}

void	store_infos(t_fill *fill)
{
	(void)fill;
	return ;
};
