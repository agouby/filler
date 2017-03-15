/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 02:46:26 by agouby            #+#    #+#             */
/*   Updated: 2017/03/15 20:17:41 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(int fd, char *line, t_fill *fill)
{
	jump_lines(fd, line, 6);
	get_next_line(fd, &line);
	if (ft_strstr(line, "agouby"))
	{
		ft_strdel(&line);
		fill->player.m = 'O';
		fill->player.o = 'X';
	}
	else
	{
		ft_strdel(&line);
		fill->player.o = 'O';
		fill->player.m = 'X';
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
	while (i < fill->map_s.y)
		get_next_line(fd, &fill->map[i++]);
	fill->map[fill->map_s.y] = NULL;
}

void	create_piece(int fd, char *line, t_fill *fill)
{
	int	i;

	i = 0;
	get_next_line(fd, &line);
	fill->piece_s.y = ft_atoi(line + 6);
	fill->piece_s.x = ft_atoi(line + 6 + ft_count_digit(fill->piece_s.y, 10));
	ft_strdel(&line);
	if (!(fill->piece = (char **)malloc(sizeof(char *) * (fill->piece_s.y + 1))))
		ft_print_error("Memory allocation failed.");
	while (i < fill->piece_s.y)
		get_next_line(fd, &fill->piece[i++]);
	fill->piece[fill->piece_s.y] = NULL;
}

void	store_infos(int fd, t_fill *fill)
{
	char	*line;

	line = NULL;
	get_player(fd, line, fill);
	get_size(fd, line, fill);
	jump_lines(fd, line, 1);
	create_map(fd, fill);
	create_piece(fd, line, fill);
}
