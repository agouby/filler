/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 02:46:26 by agouby            #+#    #+#             */
/*   Updated: 2017/03/13 07:53:05 by agouby           ###   ########.fr       */
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
		fill->player = 'O';
	}
	else
	{
		ft_strdel(&line);
		fill->player = 'X';
	}
}

void	get_size(int fd, char *line, t_fill *fill)
{
	jump_lines(fd, line, 2);
	get_next_line(fd, &line);
	fill->y_m = ft_atoi(line + 8);
	fill->x_m = ft_atoi(line + 8 + ft_count_digit(fill->y_m, 10));
	ft_strdel(&line);
}

void	create_map(int fd, t_fill *fill)
{
	size_t	i;

	i = 0;
	if (!(fill->map = (char **)malloc(sizeof(char *) * (fill->y_m + 1))))
		ft_print_error("Memory allocation failed.");
	while (i < fill->y_m)
		get_next_line(fd, &fill->map[i++]);
	fill->map[fill->y_m] = NULL;
}

void	create_piece(int fd, char *line, t_fill *fill)
{
	size_t	i;

	i = 0;
	get_next_line(fd, &line);
	fill->y_p = ft_atoi(line + 6);
	fill->x_p = ft_atoi(line + 6 + ft_count_digit(fill->y_p, 10));
	ft_strdel(&line);
	if (!(fill->piece = (char **)malloc(sizeof(char *) * (fill->y_p + 1))))
		ft_print_error("Memory allocation failed.");
	while (i < fill->y_p)
		get_next_line(fd, &fill->piece[i++]);
	fill->piece[fill->y_p] = NULL;
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
