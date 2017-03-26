/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 06:04:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/26 11:23:45 by agouby           ###   ########.fr       */
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

int		is_overlap(t_fill *f, t_play *p)
{
	t_coord i;
	int		count;

	count = 0;
	i.y = 0;
	while (count < 2 && i.y < f->pie_s.y)
	{
		i.x = 0;
		while (count < 2 && i.x < f->pie_s.x)
		{
			if (f->piece[i.y][i.x] == '*')
			{
				if (i.y + p->pie_pos.y >= f->map_s.y || i.y + p->pie_pos.y < 0
						|| i.x + p->pie_pos.x >= f->map_s.x || i.x + p->pie_pos.x < 0)
					return (1);
				if (f->map[p->pie_pos.y + i.y][p->pie_pos.x + i.x + 4] == p->op.c)
					return (1);
				if (f->map[p->pie_pos.y + i.y][p->pie_pos.x + i.x + 4] == p->me.c)
					count++;
				if (!p->touched)
					check_touched(f, p, i);
				else
					get_neighbors(f, p, i);
			}
			i.x++;
		}
		i.y++;
	}
	return (count - 1);
}
