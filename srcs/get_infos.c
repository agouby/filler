/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 02:46:26 by agouby            #+#    #+#             */
/*   Updated: 2017/03/16 20:45:09 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(int fd, char *line, t_play *play)
{
	jump_lines(fd, line, 6);
	get_next_line(fd, &line);
	if (ft_strstr(line, "agouby") && line[10] == '1')
	{
		ft_strdel(&line);
		play->me.c = 'O';
		play->op.c = 'X';
	}
	else
	{
		ft_strdel(&line);
		play->op.c = 'O';
		play->me.c = 'X';
	}
}

void	get_size(int fd, char *line, t_fill *fill)
{
	jump_lines(fd, line, 2);
	get_next_line(fd, &line);
	fill->map_s.y = ft_atoi(line + 8);
	fill->map_s.x = ft_atoi(line + 8 + ft_count_digit(fill->map_s.y, 10));
	ft_strdel(&line);
}

void	create_map(int fd, t_fill *fill)
{
	int	i;

	i = 0;
	if (!(fill->map = (char **)malloc(sizeof(char *) * (fill->map_s.y + 1))))
		ft_print_error("Memory allocation failed.");
	while (i < fill->map_s.y && get_next_line(fd, &fill->map[i]))
	{
		fill->map[i] = ft_strtoupper(fill->map[i]);
		i++;
	}
	fill->map[fill->map_s.y] = NULL;
}

void	create_pie(int fd, char *line, t_fill *fill)
{
	int	i;

	i = 0;
	get_next_line(fd, &line);
	fill->pie_s.y = ft_atoi(line + 6);
	fill->pie_s.x = ft_atoi(line + 6 + ft_count_digit(fill->pie_s.y, 10));
	ft_strdel(&line);
	if (!(fill->piece = (char **)malloc(sizeof(char *) * (fill->pie_s.y + 1))))
		ft_print_error("Memory allocation failed.");
	while (i < fill->pie_s.y)
		get_next_line(fd, &fill->piece[i++]);
	fill->piece[fill->pie_s.y] = NULL;
}

void	store_infos(int fd, t_fill *fill, t_play *play)
{
	char	*line;

	line = NULL;
	get_player(fd, line, play);
	get_size(fd, line, fill);
	jump_lines(fd, line, 1);
	create_map(fd, fill);
	create_pie(fd, line, fill);
}
