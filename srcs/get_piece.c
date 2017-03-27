/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:06:31 by agouby            #+#    #+#             */
/*   Updated: 2017/03/27 17:29:38 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_pos_piece(t_fill *fill, t_play *play)
{
	update_dir(fill, play);
	if (ft_strequ("LU", play->dir))
		chk_dir_u(fill, play, ft_strrchr);
	else if (ft_strequ("RU", play->dir))
		chk_dir_u(fill, play, ft_strchr);
	else if (ft_strequ("LD", play->dir))
		chk_dir_d(fill, play, ft_strrchr);
	else if (ft_strequ("RD", play->dir))
		chk_dir_d(fill, play, ft_strchr);
	play->pie_pos.y = play->me.pos.y - play->pie_pos.y;
	play->pie_pos.x = play->me.pos.x - play->pie_pos.x;
}
