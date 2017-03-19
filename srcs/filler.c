/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:13:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/16 19:00:03 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	filler(void)
{
	int		fd;
	t_fill	fill;
	t_play	play;

	if ((fd = open("test/map00", O_RDONLY)) == -1)
		ft_print_error("Open failed.");
	init_structs(&fill, &play);
	store_infos(fd, &fill, &play);
	get_closest_pos(&fill, &play);
	fill.map[play.op.pos.y][play.op.pos.x + 4] = ft_tolower(play.op.c);
	fill.map[play.me.pos.y][play.me.pos.x + 4] = ft_tolower(play.me.c);
	get_direction(&play);
	get_quarter(&fill, &play.me);
	get_quarter(&fill, &play.op);
	get_piece(&fill, &play);
	print_map(fill.map);
	print_piece(fill.piece);
//	ft_printf("Me : %c\nOp : %c\n\n", play.me.c, play.op.c);
//	ft_printf("My first position : [%d, %d]\n", play.me.first.x, play.me.first.y);
//	ft_printf("Op first position : [%d, %d]\n\n", play.op.first.x, play.op.first.y);
//	ft_printf("My last position : [%d, %d]\n", play.me.last.x, play.me.last.y);
//	ft_printf("Op last position : [%d, %d]\n\n", play.op.last.x, play.op.last.y);
//	ft_printf("Direction is : %s\n\n", play.dir);
//	ft_printf("My position : [%d, %d]\n", play.me.pos.x, play.me.pos.y);
//	ft_printf("Op position : [%d, %d]\n\n", play.op.pos.x, play.op.pos.y);
//	ft_printf("Smallest distance : [%d]\n\n", play.help.small_dist);
//	ft_printf("I am in the quarter : %s\n\n", play.me.quart);
//	ft_printf("He is in the quarter : %s\n", play.op.quart);
//	ft_printf("Piece pos is : [%d, %d]\n", play.pie_pos.y, play.pie_pos.x);
//	ft_printf("Piece len is : [%d, %d]\n", play.pie_len.y, play.pie_len.x);
//	ft_printf("nb X = %d, nb O = %d\n", fill.xc, fill.oc);
	print_dist(&fill);
	del_arrays(&fill);
}

int		main(void)
{
	filler();
	return (0);
}
