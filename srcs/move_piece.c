/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 22:10:16 by agouby            #+#    #+#             */
/*   Updated: 2017/03/29 01:12:06 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_start_piece(t_fill *fill, t_play *play)
{
	chk_dir_d(fill, play, ft_strchr);
	if (play->pie_pos.y != 0)
		play->pie_pos.y = play->pie_pos.y - fill->pie_s.y + 1;
	if (play->pie_pos.x != 0)
		play->pie_pos.x = play->pie_pos.x - fill->pie_s.x + 1;
}

void	move_piece(t_fill *f, t_play *p)
{
	t_coord tmp;
	t_coord tmp2;

	get_start_piece(f, p);
	tmp = p->pie_pos;
	tmp2 = p->pie_pos;
	while (p->pie_pos.y < f->map_s.y)
	{
		p->pie_pos.x = tmp2.x;
		while (p->pie_pos.x < f->map_s.x)
		{
			p->nei_pts = 0;
			if (is_overlap(f, p) == 0)
			{
				if (p->nei_pts >= p->best_nei)
				{
					p->best_nei = p->nei_pts;
					tmp = p->pie_pos;
				}
			}
			p->pie_pos.x++;
		}
		p->pie_pos.y++;
	}
	p->pie_pos = tmp;
}

void	get_neighbors(t_fill *f, t_play *p, t_coord i)
{
	t_coord n;

	n.y = -1;
	n.x = -1;
	while (n.y < 2)
	{
		n.x = -1;
		while (n.x < 2)
		{
			if (i.y + p->pie_pos.y + n.y < 0
				|| i.y + p->pie_pos.y + n.y >= f->map_s.y
				|| i.x + p->pie_pos.x + n.x < 0
				|| i.x + p->pie_pos.x + n.x >= f->map_s.x)
				return ;
			if (f->map[i.y + p->pie_pos.y + n.y][i.x + p->pie_pos.x + n.x + 4]
					== p->op.c)
				p->nei_pts += 50;
			if (f->map[i.y + p->pie_pos.y + n.y][i.x + p->pie_pos.x + n.x + 4]
					== p->me.c)
				p->nei_pts += 1;
			n.x++;
		}
		n.y++;
	}
}
