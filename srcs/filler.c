/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:13:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/15 12:01:04 by agouby           ###   ########.fr       */
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
/*	ft_printf("\nMy pos is : [%d, %d]\n", play.m_pos.x, play.m_pos.y);
	ft_printf("His pos is : [%d, %d]\n", play.o_pos.x, play.o_pos.y);
	get_direction(&play);
*/	ft_printf("La direction est : %s\n", play.dir);
	ft_printf("Premiere position Me: [%d, %d]\n", play.first_m.x, play.first_m.y);
	ft_printf("Derniere position Me: [%d, %d]\n", play.last_m.x, play.last_m.y);
	ft_printf("Premiere position Op: [%d, %d]\n", play.first_o.x, play.first_o.y);
	ft_printf("Derniere position Op: [%d, %d]\n", play.last_o.x, play.last_o.y);
	ft_printf("Next position Op: [%d, %d]\n", play.next_o.x, play.next_o.y);
	del_arrays(&fill);
}

int		main(void)
{
	filler();
	return (0);
}
