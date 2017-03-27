/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:13:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/27 20:55:01 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include <fcntl.h>

void	filler(void)
{
	int		fd;
	int		fd2;
	t_fill	fill;
	t_play	play;

	fd = 0;
	fd2 = open("lol", O_RDWR);
	static_init(&fill, &play);
	get_player(fd, &play);
	while (1)
	{
		init_structs(&fill, &play);
		store_infos(fd, &fill, &play, fd2);
		play.help.small_dist = fill.map_s.y * fill.map_s.x;
		if (play.touched == 0)
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
