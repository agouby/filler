/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:13:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/14 13:39:15 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	filler(void)
{
	int		fd;
	t_fill	fill;
	t_play	play;

	init_structs(&fill, &play);
	if ((fd = open("test/map00", O_RDONLY)) == -1)
		ft_print_error("Open failed.");
	store_infos(fd, &fill);
	get_closest_pos(&fill, &play);
	ft_printf("Je suis le joueur : %c\nMon adversaire est : %c\n\n", fill.player.m, fill.player.o);
	ft_printf("La map fait %d x %d\n\n", fill.map_s.y, fill.map_s.x);
	ft_printf("La piece fait %d x %d\n\n", fill.piece_s.y, fill.piece_s.x);
	print_map(fill.map);
	ft_printf("\n");
	print_piece(fill.piece);
	ft_printf("\nMy pos is : [%d, %d]\n", play.m_pos.x, play.m_pos.y);
	ft_printf("\nHis pos is : [%d, %d]\n\n", play.o_pos.x, play.o_pos.y);
	get_direction(&play);
	ft_printf("La direction est : %s\n", play.dir);
	del_arrays(&fill);
}

int		main(void)
{
	filler();
	return (0);
}
