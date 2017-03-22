/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:26:59 by agouby            #+#    #+#             */
/*   Updated: 2017/03/22 19:03:35 by agouby           ###   ########.fr       */
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
}

void	sort_tab(t_fill *fill)
{
	int i;

	i = 0;
	while (i < fill->nb_pos - 1)
	{
		if (fill->d_tab[i][0] > fill->d_tab[i + 1][0])
		{
			ft_swap_tab(&fill->d_tab[i], &fill->d_tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

void	store_all_dist(t_fill *fill, t_play *play)
{
	*fill->d_tab = (int *)malloc(sizeof(int) * 5);
	(*fill->d_tab)[0] = play->help.tmp_dist;
	(*fill->d_tab)[1] = play->me.pos.y;
	(*fill->d_tab)[2] = play->me.pos.x;
	(*fill->d_tab)[3] = play->op.pos.y;
	(*fill->d_tab)[4] = play->op.pos.x;
	fill->d_tab++;
}

void	get_dist(t_fill *fill, t_play *play)
{
	fill->nb_pos = fill->oc * fill->xc;
	if (!(fill->d_tab = (int **)malloc(sizeof(int *) * fill->nb_pos)))
		ft_print_error("Memory allocation failed.");
	play->op.pos = play->op.first;
	while (play->op.pos.y != -1 || play->op.pos.x != -1)
	{
		play->me.pos.x = play->me.first.x;
		play->me.pos.y = play->me.first.y;
		while (play->me.pos.y != -1 || play->me.pos.x != -1)
		{
			calculate_dist(play);
			store_all_dist(fill, play);
			get_next_pos(fill, &play->me);
		}
		get_next_pos(fill, &play->op);
	}
	fill->d_tab -= fill->nb_pos;
	sort_tab(fill);
}
