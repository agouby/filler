/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:32:37 by agouby            #+#    #+#             */
/*   Updated: 2017/03/27 17:31:01 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_quarter(t_fill *fill, t_player *player)
{
	if (player->pos.x < (fill->map_s.x / 2))
		player->quart[0] = 'L';
	else
		player->quart[0] = 'R';
	if (player->pos.y < (fill->map_s.y / 2))
		player->quart[1] = 'U';
	else
		player->quart[1] = 'D';
}

void	chk_dir_u(t_fill *fill, t_play *play, char *(*f)(const char *, int))
{
	int		i;
	char	*s;

	s = NULL;
	i = fill->pie_s.y - 1;
	while (i >= 0 && !(s = f(fill->piece[i], '*')))
		i--;
	play->pie_pos.y = i;
	play->pie_pos.x = s - fill->piece[i];
}

void	chk_dir_d(t_fill *fill, t_play *play, char *(*f)(const char *, int))
{
	int		i;
	char	*s;

	s = NULL;
	i = 0;
	while (i < fill->pie_s.y && !(s = f(fill->piece[i], '*')))
		i++;
	play->pie_pos.y = i;
	play->pie_pos.x = s - fill->piece[i];
}

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
