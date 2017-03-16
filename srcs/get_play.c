/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 07:49:31 by agouby            #+#    #+#             */
/*   Updated: 2017/03/16 11:12:11 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_first_pos(t_fill *fill, t_play *play, char player)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = NULL;
	while (!(tmp = ft_strchr(fill->map[i], player)))
		i++;
	if (player == fill->player.m)
	{
		play->first_m.x = tmp - 4 - fill->map[i];
		play->first_m.y = i;
		play->pos_m = play->first_m; 
		return ;
	}
	play->first_o.x = tmp - 4 - fill->map[i];
	play->first_o.y = i;
	play->pos_o = play->first_o; 
}

void	get_last_pos(t_fill *fill, t_play *play, char player)
{
	char	*tmp;
	size_t	i;

	i = fill->map_s.y - 1;
	tmp = NULL;
	while (!(tmp = ft_strrchr(fill->map[i], player)))
		i--;
	if (player == fill->player.m)
	{
		play->last_m.x = tmp - 4 - fill->map[i];
		play->last_m.y = i;
		return ;
	}
	play->last_o.x = tmp - 4 - fill->map[i];
	play->last_o.y = i;
}

void	get_next_pos_o(t_fill *fill, t_play *play)
{
	char	*srch;

	srch = NULL;
	play->next_o.x = play->pos_o.x;
	play->next_o.y = play->pos_o.y;
	if (play->next_o.x == play->last_o.x && play->next_o.y == play->last_o.y)
	{
		play->pos_o.x = -1;
		play->pos_o.y = -1;
		return ;
	}
	if ((srch = ft_strchr(fill->map[play->pos_o.y] + play->next_o.x + 5, fill->player.o)))
	{
		play->next_o.x = srch - fill->map[play->pos_o.y] - 4;
		play->pos_o.x = srch - fill->map[play->pos_o.y] - 4;
	}
	else
	{
		while (play->next_o.y <= play->last_o.y)
		{
			play->next_o.y++;
			play->next_o.x = 0;
			if ((srch = ft_strchr(fill->map[play->next_o.y] + 4, fill->player.o)))
			{
				play->pos_o.x = srch - fill->map[play->next_o.y] - 4;
				play->pos_o.y = play->next_o.y;
				return;
			}
		}
	}
}

void	get_next_pos_m(t_fill *fill, t_play *play)
{
	char	*srch;

	srch = NULL;
	play->next_m.x = play->pos_m.x;
	play->next_m.y = play->pos_m.y;
	if (play->next_m.x == play->last_m.x && play->next_m.y == play->last_m.y)
	{
		play->pos_m.x = -1;
		play->pos_m.y = -1;
		return ;
	}
	if ((srch = ft_strchr(fill->map[play->pos_m.y] + play->next_m.x + 5, fill->player.m)))
	{
		play->next_m.x = srch - fill->map[play->pos_m.y] - 4;
		play->pos_m.x = srch - fill->map[play->pos_m.y] - 4;
	}
	else
	{
		while (play->next_m.y <= play->last_m.y)
		{
			play->next_m.y++;
			play->next_m.x = 0;
			if ((srch = ft_strchr(fill->map[play->next_m.y] + 4, fill->player.m)))
			{
				play->pos_m.x = srch - fill->map[play->next_m.y] - 4;
				play->pos_m.y = play->next_m.y;
				return;
			}
		}
	}
}

void	get_closest_pos(t_fill *fill, t_play *play, t_help *help)
{
	get_first_pos(fill, play, fill->player.m);
	get_first_pos(fill, play, fill->player.o);
	get_last_pos(fill, play, fill->player.m);
	get_last_pos(fill, play, fill->player.o);
	get_hypo(fill, play, help);
	play->pos_o = help->pos_o_saved;
	play->pos_m = help->pos_m_saved;
}
