/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:32:37 by agouby            #+#    #+#             */
/*   Updated: 2017/03/24 19:58:02 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_direction(t_play *play)
{
	if (play->op.pos.x - play->me.pos.x < 0)
		play->dir[0] = 'L';
	else if (play->op.pos.x - play->me.pos.x > 0)
		play->dir[0] = 'R';
	else
		play->dir[0] = '-';
	if (play->op.pos.y - play->me.pos.y < 0)
		play->dir[1] = 'U';
	else if (play->op.pos.y - play->me.pos.y > 0)
		play->dir[1] = 'D';
	else
		play->dir[1] = '-';
}
