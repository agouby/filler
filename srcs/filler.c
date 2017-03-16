/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:13:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/16 11:10:53 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	filler(void)
{
	int		fd;
	t_fill	fill;
	t_play	play;
	t_help	help;

	init_structs(&fill, &play, &help);
	if ((fd = open("test/map00", O_RDONLY)) == -1)
		ft_print_error("Open failed.");
	store_infos(fd, &fill);
	ft_printf("Me : %c\nOp : %c\n\n", fill.player.m, fill.player.o);
	get_closest_pos(&fill, &play, &help);
	fill.map[play.pos_o.y][play.pos_o.x + 4] = ft_tolower(fill.player.o);
	fill.map[play.pos_m.y][play.pos_m.x + 4] = ft_tolower(fill.player.m);
	print_map(fill.map);
	ft_printf("\n");
	print_piece(fill.piece);
	get_direction(&play);
	ft_printf("My first position : [%d, %d]\n", play.first_m.x, play.first_m.y);
	ft_printf("Op first position : [%d, %d]\n\n", play.first_o.x, play.first_o.y);
	ft_printf("My last position : [%d, %d]\n", play.last_m.x, play.last_m.y);
	ft_printf("Op last position : [%d, %d]\n\n", play.last_o.x, play.last_o.y);
	ft_printf("Direction is : %s\n\n", play.dir);
	ft_printf("My position : [%d, %d]\n", play.pos_m.x, play.pos_m.y);
	ft_printf("Op position : [%d, %d]", play.pos_o.x, play.pos_o.y);
	del_arrays(&fill);
}

int		main(void)
{
	filler();
	return (0);
}
