/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_score.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:29:41 by agouby            #+#    #+#             */
/*   Updated: 2017/03/27 21:06:28 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	v_draw_score_bk(t_v *v)
{
	t_coord i;

	i.y = 100;
	while (i.y < 880)
	{
		i.x = 1100;
		while (i.x < 1200)
		{
			draw_pixel(i.y, i.x, v, 0xFFFFFF);
			i.x++;
		}
		i.y++;
	}
}

void	get_size_score(t_v *v)
{
	v->nb_pos = v->map_s.y * v->map_s.x;	
}

