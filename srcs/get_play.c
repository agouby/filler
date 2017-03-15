/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 07:49:31 by agouby            #+#    #+#             */
/*   Updated: 2017/03/15 12:23:31 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_first_pos(t_fill *fill, t_play *play, char player)
{
	char	*tmp;
	size_t	i;
	int		found;

	i = 0;
	found = 0;
	while (!found)
	{
		if ((tmp = ft_strchr(fill->map[i], player)))
		{
			if (player == fill->player.m)
			{
				play->first_m.x = tmp - 4 - fill->map[i];
				play->first_m.y = i;
				play->pos_m.x = play->first_m.x; 
				play->pos_m.y = play->first_m.y; 
				found = 1;
			}
			else
			{
				play->first_o.x = tmp - 4 - fill->map[i];
				play->first_o.y = i;
				play->pos_o.x = play->first_o.x; 
				play->pos_o.y = play->first_o.y; 
				found = 1;
			}
		}
		i++;
	}
}

void	get_last_pos(t_fill *fill, t_play *play, char player)
{
	char	*tmp;
	size_t	i;
	int		found;

	i = fill->map_s.y - 1;
	found = 0;
	while (!found)
	{
		if ((tmp = ft_strrchr(fill->map[i], player)))
		{
			if (player == fill->player.m)
			{
				play->last_m.x = tmp - 4 - fill->map[i];
				play->last_m.y = i;
				found = 1;
			}
			else
			{
				play->last_o.x = tmp - 4 - fill->map[i];
				play->last_o.y = i;
				found = 1;
			}
		}
		i--;
	}
}

void	get_next_pos(t_fill *fill, t_play *play)
{
	play->next_o.x = play->pos_o.x;
	play->next_o.y = play->pos_o.y;
	ft_printf("%d %d\n", play->next_o.y, play->next_o.x);
	if (play->next_o.y == play->last_o.y)
	{
		while (play->next_o.x != play->last_o.x && play->next_o.x != fill->map_s.x)
		{
			play->next_o.x++;
			if (fill->map[play->next_o.y][play->next_o.x + 4] == 'X')
			{
				play->pos_o.x = play->next_o.x;
				play->pos_o.y = play->next_o.y;
				return;
			}
		}
	}
/*	while (fill->first_o.y != fill->last_o.y)
	{

	}
*/
}

void	get_closest_pos(t_fill *fill, t_play *play)
{
	get_first_pos(fill, play, fill->player.m);
	get_first_pos(fill, play, fill->player.o);
	get_last_pos(fill, play, fill->player.m);
	get_last_pos(fill, play, fill->player.o);
	get_next_pos(fill, play);
}

/*void	get_direction(t_play *play)
{
	if (play->o_pos.x - play->m_pos.x < 0)
		play->dir[0] = 'L';
	else if (play->o_pos.x - play->m_pos.x > 0)
		play->dir[0] = 'R';
	else
		play->dir[0] = '-';
	if (play->o_pos.y - play->m_pos.y < 0)
		play->dir[1] = 'U';
	else if (play->o_pos.y - play->m_pos.y > 0)
		play->dir[1] = 'D';
	else
		play->dir[1] = '-';
}
*/
