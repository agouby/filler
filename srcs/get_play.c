/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 07:49:31 by agouby            #+#    #+#             */
/*   Updated: 2017/03/13 08:23:17 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_first_pos(t_fill *fill)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (fill->map[y])
	{
		while (fill->map[y][x] != '\n')
		{
			if (fill->map[y][x] == fill->player)
			{
				play->o_start.x = x;
				play->o_start.y = y;
			}
		}
	}
}
