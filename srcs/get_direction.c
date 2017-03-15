/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:32:37 by agouby            #+#    #+#             */
/*   Updated: 2017/03/15 20:48:09 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_direction(t_play *play)
{
	if (play->pos_o.x - play->pos_m.x < 0)
		play->dir[0] = 'L';
	else if (play->pos_o.x - play->pos_m.x > 0)
		play->dir[0] = 'R';
	else
		play->dir[0] = '-';
	if (play->pos_o.y - play->pos_m.y < 0)
		play->dir[1] = 'U';
	else if (play->pos_o.y - play->pos_m.y > 0)
		play->dir[1] = 'D';
	else
		play->dir[1] = '-';
}
