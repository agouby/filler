/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 02:46:26 by agouby            #+#    #+#             */
/*   Updated: 2017/03/27 21:09:13 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(int fd, t_play *play)
{
	char *line;

	get_next_line(fd, &line);
	if (line[10] == '1' && ft_strstr(line, "agouby"))
	{
		play->me.c = 'O';
		play->op.c = 'X';
	}
	else
	{
		play->me.c = 'X';
		play->op.c = 'O';
	}
	ft_strdel(&line);
}

void	get_size(int fd, char *line, t_fill *fill)
{
	get_next_line(fd, &line);
	fill->map_s.y = ft_atoi(line + 8);
	fill->map_s.x = ft_atoi(line + 8 + ft_count_digit(fill->map_s.y, 10));
	ft_strdel(&line);
}

void	create_map(int fd, t_fill *fill, t_play *play)
{
	int	i;
	int n;

	i = 0;
	n = 0;
	if (!(fill->map = (char **)malloc(sizeof(char *) * (fill->map_s.y + 1))))
		ft_print_error("Memory allocation failed.");
	while (i < fill->map_s.y && get_next_line(fd, &fill->map[i]))
	{
		n = 0;
		while (fill->map[i][n])
		{
			if (fill->map[i][n++] == play->op.c)
				fill->nb_op++;
		}
		i++;
	}
	if (fill->last_nb_op == fill->nb_op)
		play->won = 1;
	else
		fill->last_nb_op = fill->nb_op;
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
	get_size(fd, line, fill);
	ft_jump_lines(fd, line, 1);
	create_map(fd, fill, play);
	create_pie(fd, line, fill);
}
