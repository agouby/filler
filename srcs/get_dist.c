/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:26:59 by agouby            #+#    #+#             */
/*   Updated: 2017/03/16 16:48:15 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	calculate_dist(t_play *play)
{
	int		vert_dist;
	int		hori_dist;

	vert_dist = ABS((play->me.pos.y - play->op.pos.y));
	hori_dist = ABS((play->me.pos.x - play->op.pos.x));
	play->help.tmp_dist = hori_dist + vert_dist;
	if (play->help.tmp_dist <= play->help.small_dist)
	{
		play->help.small_dist = play->help.tmp_dist;
		play->help.pos_o_saved = play->op.pos;
		play->help.pos_m_saved = play->me.pos;
	}
}

void	get_dist(t_fill *fill, t_play *play)
{
	play->op.pos = play->op.first;
	play->help.pos_o_saved = play->op.pos;
	play->help.pos_m_saved = play->me.pos;
	play->help.small_dist = fill->map_s.x + fill->map_s.y;
	while (play->op.pos.y != -1 || play->op.pos.x != -1)
	{
		play->me.pos.x = play->me.first.x;
		play->me.pos.y = play->me.first.y;
		while (play->me.pos.y != -1 || play->me.pos.x != -1)
		{
			calculate_dist(play);
			get_next_pos(fill, &play->me);
		}
		get_next_pos(fill, &play->op);
	}
}
