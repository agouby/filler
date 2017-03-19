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

void	change_and_count(t_fill *fill, char **line)
{
	size_t i;

	i = 0;
	while (line[0][i])
	{
		if (line[0][i] == 'X' || line[0][i] == 'x')
		{
			line[0][i] = ft_toupper(line[0][i]);
			fill->xc++;
		}
		else if (line[0][i] == 'O' || line[0][i] == 'o')
		{
			line[0][i] = ft_toupper(line[0][i]);
			fill->oc++;
		}
		i++;
	}
}

int	*store_all_dist(t_fill *fill, t_play *play)
{
	fill->d_tab[0] = (int *)malloc(sizeof(int) * 80);
	fill->d_tab[0][0] = play->help.tmp_dist;
	fill->d_tab[0][1] = play->me.pos.y;
//	*(fill->d_tab)[2] = play->me.pos.x;
//	*(fill->d_tab)[3] = play->op.pos.y;
//	*(fill->d_tab)[4] = play->op.pos.x;
	ft_printf("lol");
//	(void)play;
	return (*fill->d_tab);
}

void	get_dist(t_fill *fill, t_play *play)
{
	int	n;
	int i;

	i = 0;
	n = fill->oc * fill->xc;
	if (!(fill->d_tab = (int **)malloc(sizeof(int *) * (n))))
		ft_print_error("Memory allocation failed.");
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
			fill->d_tab[i] = store_all_dist(fill, play);
			i++;
			get_next_pos(fill, &play->me);
		}
		get_next_pos(fill, &play->op);
	}
}
