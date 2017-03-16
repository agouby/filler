/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 02:28:55 by agouby            #+#    #+#             */
/*   Updated: 2017/03/16 09:54:43 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		init_coord(t_coord *co)
{
	co->x = 0;
	co->y = 0;
}

static void	init_fill_struct(t_fill *fill)
{
	fill->map = NULL;
	fill->piece = NULL;
	init_coord(&fill->map_s);
	init_coord(&fill->pie_s);
	fill->player.m = 0;
	fill->player.o = 0;
}

static void	init_play_struct(t_play *play)
{
	init_coord(&play->pos_o);
	init_coord(&play->pos_m);
	init_coord(&play->first_o);
	init_coord(&play->first_m);
	init_coord(&play->last_o);
	init_coord(&play->last_m);
	init_coord(&play->next_o);
	init_coord(&play->next_m);
	ft_bzero(play->dir, 3);
}

static void	init_help_struct(t_help *help)
{
	help->hypo_tmp = 0;
	help->small_hypo = 99999999;
	init_coord(&help->pos_o_saved);
	init_coord(&help->pos_m_saved);
}

void		init_structs(t_fill *fill, t_play *play, t_help *help)
{
	init_fill_struct(fill);
	init_play_struct(play);
	init_help_struct(help);
}
