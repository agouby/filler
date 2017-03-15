/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 06:04:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/15 20:21:17 by agouby           ###   ########.fr       */
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

void	calculate_hypo(t_play *play, t_help *help)
{
	int		ver_angl;
	int		hor_angl;

	ver_angl = ABS((play->pos_m.y - play->pos_o.y));
	hor_angl = ABS((play->pos_m.x - play->pos_o.x));
	ft_printf("va, ha %d %d\n", ver_angl, hor_angl);
	help->hypo_tmp = sqrt(ft_pow(ver_angl, 2) + ft_pow(hor_angl, 2));
	if (help->hypo_tmp <= help->small_hypo)
	{
		help->small_hypo = help->hypo_tmp;
		help->pos_o_saved = play->pos_o;
		help->pos_m_saved = play->pos_m;
	}
}
