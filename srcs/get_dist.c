/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:26:59 by agouby            #+#    #+#             */
/*   Updated: 2017/03/25 06:53:22 by agouby           ###   ########.fr       */
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
	if (play->help.tmp_dist < play->help.small_dist)
	{
		play->me.tmp = play->me.pos;
//		ft_printf("Me = [%d, %d]\n", play->me.tmp.y, play->me.tmp.x);
		play->op.tmp = play->op.pos;
//		ft_printf("Op = [%d, %d]\n", play->op.tmp.y, play->op.tmp.x);
		play->me.tmp2 = play->pie_pos;
//		ft_printf("Pie = [%d, %d]\n", play->me.tmp2.y, play->me.tmp2.x);
		play->help.small_dist = play->help.tmp_dist;
	}
}

void	get_dist(t_fill *fill, t_play *play)
{
	int tmp;
	tmp = 0;
	fill->nb_pos = fill->oc * fill->xc;
	play->op.pos = play->op.first;
	while (play->op.pos.y != -1 || play->op.pos.x != -1)
	{
		play->me.pos.x = play->me.first.x;
		play->me.pos.y = play->me.first.y;
		while (play->me.pos.y != -1 || play->me.pos.x != -1)
		{
			tmp++;
			if (!is_overlap(fill, play))
			{
				calculate_dist(play);
			}
			else
				play->cnt++;
			get_next_pos(fill, &play->me);
		}
		get_next_pos(fill, &play->op);
	}
	play->me.pos = play->me.tmp;
	play->op.pos = play->op.tmp;
	play->pie_pos = play->me.tmp2;
}
