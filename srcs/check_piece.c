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

void	change_dir(t_play *play)
{
	if (play->dir[1] == '-')
	{
		if (play->me.quart[1] == 'U')
			play->dir[1] = 'D';
		else if (play->me.quart[1] == 'D')
			play->dir[1] = 'U';
	}
	else if (play->dir[0] == '-')
	{
		if (play->me.quart[0] == 'L')
			play->dir[0] = 'R';
		else if (play->me.quart[0] == 'R')
			play->dir[0] = 'L';
	}
}

void	get_pos_piece(t_fill *fill, t_play *play)
{
	change_dir(play);
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
	if (is_overlap(fill, p))
		ft_print_error("Overlap retard <333");
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

int	is_overlap(t_fill *f, t_play *p)
{
	t_coord i;

	i.y = 0;
	while (i.y < f->pie_s.y)
	{
		i.x = 0;
		while (i.x < f->pie_s.x)
		{
			if (f->piece[i.y][i.x] == '*' && f->map[p->pie_pos.y][p->pie_pos.x] != '.')
					return (1);
			i.x++;
		}
		i.y++;
	}
	return (0);
}

void	get_piece(t_fill *fill, t_play *play)
{
	get_pos_piece(fill, play);
	print_piece_map(fill, play);
}
