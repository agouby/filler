/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 22:10:16 by agouby            #+#    #+#             */
/*   Updated: 2017/03/26 06:48:28 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_start_piece(t_fill *fill, t_play *play)
{
	chk_dir_d(fill, play, ft_strchr);
	if (play->pie_pos.y != 0)
		play->pie_pos.y = play->pie_pos.y - fill->pie_s.y + 1;
	if (play->pie_pos.x != 0)
		play->pie_pos.x = play->pie_pos.x - fill->pie_s.x + 1;
}

void	move_piece(t_fill *f, t_play *p)
{
	t_coord tmp;

	get_start_piece(f ,p);
	tmp = p->pie_pos;
	while (p->pie_pos.y < f->map_s.y)
	{
		p->pie_pos.x = tmp.x;
		while (p->pie_pos.x < f->map_s.x)
		{
			if (is_overlap(f, p) == 0)
				return ;
			p->pie_pos.x++;
		}
		p->pie_pos.y++;
	}
	ft_print_error("RIP RETARD");
}
