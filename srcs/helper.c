/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 06:04:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/16 11:31:55 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	jump_lines(int fd, char *line, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n)
	{
		get_next_line(fd, &line);
		ft_strdel(&line);
	}
}

void	calculate_dist(t_play *play, t_help *help)
{
	int		vert_dist;
	int		hori_dist;

	vert_dist = ABS((play->pos_m.y - play->pos_o.y));
	hori_dist = ABS((play->pos_m.x - play->pos_o.x));
	help->tmp_dist = hori_dist + vert_dist;
	if (help->tmp_dist <= help->small_dist)
	{
		help->small_dist = help->tmp_dist;
		help->pos_o_saved = play->pos_o;
		help->pos_m_saved = play->pos_m;
	}
}
