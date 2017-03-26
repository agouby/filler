/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:13:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/26 15:11:10 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	filler(void)
{
	int		fd;
	t_fill	fill;
	t_play	play;

	fd = 0;
	play.touched = 0;
	get_player(fd, &play);
	while (1)
	{
		play.help.small_dist = 9999999;
		init_structs(&fill, &play);
		store_infos(fd, &fill);
		if (!play.touched)
			get_closest_pos(&fill, &play);
		else
			move_piece(&fill, &play);
		ft_printf("%d %d\n", play.pie_pos.y, play.pie_pos.x);
		del_arrays(&fill);
	}
}

int		main(void)
{
	filler();
	return (0);
}
