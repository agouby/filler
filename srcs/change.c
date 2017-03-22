/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:42:04 by agouby            #+#    #+#             */
/*   Updated: 2017/03/22 12:42:22 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	change_dir(t_play *play)
{
	if (play->dir[1] == '-')
	{
		if (play->me.quart[1] == 'U')
			play->dir[1] = 'D';
		else if (play->me.quart[1] == 'D')
			play->dir[1] = 'U';
	}
	else if (play->dir[0] == '-')
	{
		if (play->me.quart[0] == 'L')
			play->dir[0] = 'R';
		else if (play->me.quart[0] == 'R')
			play->dir[0] = 'L';
	}
}
