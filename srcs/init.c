/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 02:28:55 by agouby            #+#    #+#             */
/*   Updated: 2017/03/14 14:05:09 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		init_coord(t_coord *co)
{
	co->x = 0;
	co->y = 0;
};

static void	init_fill_struct(t_fill *fill)
{
	fill->map = NULL;
	fill->piece = NULL;
	init_coord(&fill->map_s);
	init_coord(&fill->piece_s);
	fill->player.m = 0;
	fill->player.o = 0;
}

static void	init_play_struct(t_play *play)
{
	init_coord(&play->o_pos);
	init_coord(&play->m_pos);
	ft_bzero(play->dir, 3);
}

void		init_structs(t_fill *fill, t_play *play)
{
	init_fill_struct(fill);
	init_play_struct(play);
}
