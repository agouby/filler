/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 06:04:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/29 01:15:08 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	del_arrays(t_fill *fill)
{
	int i;

	i = 0;
	while (i < fill->map_s.y)
		free(fill->map[i++]);
	free(fill->map);
	i = 0;
	while (i < fill->pie_s.y)
		free(fill->piece[i++]);
	free(fill->piece);
}

void	end_next_pos(t_player *player)
{
	player->pos.x = -1;
	player->pos.y = -1;
}

int		deal_with_star(t_fill *f, t_play *p, t_coord i)
{
	int count;

	count = 0;
	if (f->piece[i.y][i.x] == '*')
	{
		if (i.y + p->pie_pos.y >= f->map_s.y || i.y + p->pie_pos.y < 0
				|| i.x + p->pie_pos.x >= f->map_s.x || i.x + p->pie_pos.x < 0)
			return (5);
		if (f->map[p->pie_pos.y + i.y][p->pie_pos.x + i.x + 4] == p->op.c)
			return (5);
		if (f->map[p->pie_pos.y + i.y][p->pie_pos.x + i.x + 4] == p->me.c)
			count++;
		if (p->touched == 0)
			check_touched(f, p, i);
		else
			get_neighbors(f, p, i);
	}
	return (count);
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
			count += deal_with_star(f, p, i);
			i.x++;
		}
		i.y++;
	}
	return (count - 1);
}
