/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:13:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/13 03:21:50 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	filler(void)
{
	int	fd;
	int	i;
	char *line;
	t_fill *fill;

	init_struct(&fill);
	line = NULL;
	if ((fd = open("test/map00", O_RDONLY)) == -1)
		ft_print_error("Open failed.");
	i = 0;
	fill->player = get_player(fd, line);
	ft_printf("Je suis le joueur : %d\n", fill->player);
	while (i++ < 3)
		get_next_line(fd, &line);
	get_size(line, &fill->x_s, &fill->y_s);
//	ft_printf("La map a une taille de : %d, %d\n", x, y);
	get_next_line(fd, &line);
	fill->map = create_map(fd, fill->y_s);
	print_map(fill->map);
	ft_strdel(&line);
}

int		main(void)
{
	filler();
	return (0);
};
