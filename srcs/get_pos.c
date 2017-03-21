/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 07:49:31 by agouby            #+#    #+#             */
/*   Updated: 2017/03/21 16:27:34 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_first_pos(t_fill *fill, t_play *play, char player)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (!(tmp = ft_strchr(fill->map[i], player)) && i < fill->map_s.y - 1)
		i++;
	if (!tmp)
		ft_print_error("Player not found.");
	if (player == play->me.c)
	{
		play->me.first.x = tmp - 4 - fill->map[i];
		play->me.first.y = i;
		play->me.pos = play->me.first;
		return ;
	}
	play->op.first.x = tmp - 4 - fill->map[i];
	play->op.first.y = i;
	play->op.pos = play->op.first;
}

void	get_last_pos(t_fill *fill, t_play *play, char player)
{
	int		i;
	char	*tmp;

	i = fill->map_s.y - 1;
	tmp = NULL;
	while (!(tmp = ft_strrchr(fill->map[i], player)))
		i--;
	if (player == play->me.c)
	{
		play->me.last.x = tmp - 4 - fill->map[i];
		play->me.last.y = i;
		return ;
	}
	play->op.last.x = tmp - 4 - fill->map[i];
	play->op.last.y = i;
}

void	get_next_pos(t_fill *fill, t_player *plyr)
{
	char	*srch;

	plyr->next = plyr->pos;
	if (plyr->next.x == plyr->last.x && plyr->next.y == plyr->last.y)
	{
		end_next_pos(plyr);
		return ;
	}
	if ((srch = ft_strchr(fill->map[plyr->pos.y] + plyr->next.x + 5, plyr->c)))
	{
		plyr->next.x = srch - fill->map[plyr->pos.y] - 4;
		plyr->pos.x = srch - fill->map[plyr->pos.y] - 4;
		return ;
	}
	while (plyr->next.y++ <= plyr->last.y && !(plyr->next.x = 0))
	{
		if ((srch = ft_strchr(fill->map[plyr->next.y] + 4, plyr->c)))
		{
			plyr->pos.x = srch - fill->map[plyr->next.y] - 4;
			plyr->pos.y = plyr->next.y;
			return ;
		}
	}
}

void	get_next_dist(t_fill *fill, t_play *play)
{
	play->help.tmp_dist = fill->d_tab[play->help.next_dist][0];
	play->me.pos.y = fill->d_tab[play->help.next_dist][1];
	play->me.pos.x = fill->d_tab[play->help.next_dist][2];
	play->op.pos.y = fill->d_tab[play->help.next_dist][3];
	play->op.pos.x = fill->d_tab[play->help.next_dist][4];
	play->help.next_dist++;
}

void	get_closest_pos(t_fill *fill, t_play *play)
{
	get_first_pos(fill, play, play->me.c);
	get_first_pos(fill, play, play->op.c);
	get_last_pos(fill, play, play->me.c);
	get_last_pos(fill, play, play->op.c);
	get_dist(fill, play);
	get_next_dist(fill, play);
}
