/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hypo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:26:59 by agouby            #+#    #+#             */
/*   Updated: 2017/03/16 11:18:23 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_hypo(t_fill *fill, t_play *play, t_help *help)
{
	play->pos_o = play->first_o;
	help->pos_o_saved = play->pos_o;
	help->pos_m_saved = play->pos_m;
	ft_printf("\nI LOVE CHEAP THRILLS [ME %d, %d] [OP %d, %d]\n", play->pos_m.y, play->pos_m.x, play->pos_o.y, play->pos_o.x);
	while (play->pos_o.y != -1 || play->pos_o.x != -1)
	{
		play->pos_m.x = play->first_m.x;
		play->pos_m.y = play->first_m.y;
		while (play->pos_m.y != -1 || play->pos_m.x != -1)
		{
			calculate_hypo(play, help);
			get_next_pos_m(fill, play);
		}
		get_next_pos_o(fill, play);
	}
}
