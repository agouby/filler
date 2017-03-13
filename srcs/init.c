/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 02:28:55 by agouby            #+#    #+#             */
/*   Updated: 2017/03/13 08:39:43 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_fill_struct(t_fill **fill)
{
	*fill = (t_fill *)malloc(sizeof(t_fill));
	(*fill)->map = NULL;
	(*fill)->m.y = 0;
	(*fill)->m.x = 0;
	(*fill)->p.y = 0;
	(*fill)->p.x = 0;
	(*fill)->piece = NULL;
	(*fill)->player_m = 0;
	(*fill)->player_o = 0;
}

static void	init_play_struct(t_play **play)
{
	*play = (t_play *)malloc(sizeof(t_play));
	(*play)->o_start.y = 0;
	(*play)->o_start.x = 0;
	(*play)->m_start.y = 0;
	(*play)->m_start.x = 0;
}

void		init_structs(t_fill **fill, t_play **play)
{
	init_fill_struct(fill);
	init_play_struct(play);
}
