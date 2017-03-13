/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:13:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/13 08:23:12 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	filler(void)
{
	int		fd;
	t_fill	*fill;
	t_play	*play;

	init_structs(&fill, &play);
	if ((fd = open("test/map00", O_RDONLY)) == -1)
		ft_print_error("Open failed.");
	store_infos(fd, fill);
	ft_printf("Je suis le joueur : %c\n\n", fill->player.x);
	ft_printf("La map fait %d x %d\n\n", fill->m.y, fill->m.x);
	ft_printf("La piece fait %d x %d\n\n", fill->p.y, fill->p.x);
	print_map(fill->map);
	ft_printf("\n");
	print_piece(fill->piece);
	del_arrays(fill);
	free(fill);
}

int		main(void)
{
	filler();
	return (0);
}
