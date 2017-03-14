/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 07:49:31 by agouby            #+#    #+#             */
/*   Updated: 2017/03/14 13:41:34 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_first_position(t_fill *fill, t_play *play, char player)
{
	char	*tmp;
	size_t	i;
	int found = 0;

	i = 0;
	while (!found)
	{
		if ((tmp = ft_strchr(fill->map[i], player)))
		{
			if (player == fill->player.m)
			{
				play->m_pos.x = tmp - 4 - fill->map[i];
				play->m_pos.y = i;
				found = 1;
			}
			else
			{
				play->o_pos.x = tmp - 4 - fill->map[i];
				play->o_pos.y = i;
				found = 1;
			}
		}
		i++;
	}
}

void	get_closest_pos(t_fill *fill, t_play *play)
{
	get_first_position(fill, play, fill->player.m);
	get_first_position(fill, play, fill->player.o);
}

void	get_direction(t_play *play)
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
