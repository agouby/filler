/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:06:31 by agouby            #+#    #+#             */
/*   Updated: 2017/03/16 20:38:58 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_dir_u(t_fill *fill, t_play *play, char *(*f)(const char *, int))
{
	int		i;
	char	*s;

	s = NULL;
	i = fill->pie_s.y - 1;
	while (!(s = f(fill->piece[i], '*')))
		i--;
	play->pie_pos.y = i;
	play->pie_pos.x = s - fill->piece[i];
}

void	check_dir_d(t_fill *fill, t_play *play, char *(*f)(const char *, int))
{
	int		i;
	char	*s;

	s = NULL;
	i = 0;
	while (!(s = f(fill->piece[i], '*')))
		i++;
	play->pie_pos.y = i;
	play->pie_pos.x = s - fill->piece[i];
}

void	get_pos_piece(t_fill *fill, t_play *play)
{
	if (ft_strequ("LU", play->dir))
		check_dir_u(fill, play, ft_strrchr);
	else if (ft_strequ("RU", play->dir))
		check_dir_u(fill, play, ft_strchr);
	else if (ft_strequ("LD", play->dir))
		check_dir_d(fill, play, ft_strrchr);
	else if (ft_strequ("RD", play->dir))
		check_dir_d(fill, play, ft_strchr);
	play->pie_pos.y = play->me.pos.y - play->pie_pos.y;
	play->pie_pos.x = play->me.pos.x - play->pie_pos.x;
}

void	print_piece_map(t_fill *fill, t_play *p)
{
	t_coord i;

	i.y = 0;
	while (i.y < fill->pie_s.y)
	{
		i.x = 0;
		while (i.x < fill->pie_s.x)
		{
			if (fill->piece[i.y][i.x] == '*')
				fill->map[p->pie_pos.y + i.y][p->pie_pos.x + i.x + 4] = '*';
			i.x++;
		}
		i.y++;
	}
	fill->map[p->me.pos.y][p->me.pos.x + 4] = p->me.c;
}

void	get_piece(t_fill *fill, t_play *play)
{
	get_pos_piece(fill, play);
	print_piece_map(fill, play);
}
