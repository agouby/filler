/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 07:49:31 by agouby            #+#    #+#             */
/*   Updated: 2017/03/13 08:52:15 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_first_pos(t_fill *fill, t_play *play)
{
	t_coord	i;

	i.y = 0;
	ft_printf("[%c]\n", fill->player_o);
	while (fill->map[i.y])
	{
		i.x = 0;
		while (fill->map[i.y][i.x] != '\0')
		{
			if (fill->map[i.y][i.x] == fill->player_o)
			{
				play->o_start.x = i.x - 4;
				play->o_start.y = i.y;
			}
			else if (fill->map[i.y][i.x] == fill->player_m)
			{
				play->m_start.x = i.x - 4;
				play->m_start.y = i.y;
			}
			i.x++;
		}
		i.y++;
	}
}
