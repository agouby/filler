/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 06:04:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/16 20:39:16 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	jump_lines(int fd, char *line, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n)
	{
		get_next_line(fd, &line);
		ft_strdel(&line);
	}
}

void	end_next_pos(t_player *player)
{
	player->pos.x = -1;
	player->pos.y = -1;
}

void	get_quarter(t_fill *fill, t_player *player)
{
	if (player->pos.x < (fill->map_s.x / 2))
		player->quart[0] = 'L';
	else
		player->quart[0] = 'R';
	if (player->pos.y < (fill->map_s.y / 2))
		player->quart[1] = 'U';
	else
		player->quart[1] = 'D';
}
