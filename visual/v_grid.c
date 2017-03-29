/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_grid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:36:05 by agouby            #+#    #+#             */
/*   Updated: 2017/03/29 00:42:50 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	v_draw_grid_h(t_v *v)
{
	int		i;
	t_coord pos;
	t_coord dist;

	i = 0;
	dist.x = v->sq_s * v->map_s.x;
	pos.y = v->of.y;
	while (i <= v->map_s.y)
	{
		pos.x = 0;
		while (pos.x <= dist.x)
		{
			draw_pixel(pos.y, pos.x, v, C_GRID);
			draw_pixel(pos.y - 1, pos.x, v, C_GRID);
			draw_pixel(pos.y + 1, pos.x, v, C_GRID);
			pos.x++;
		}
		pos.y += v->sq_s;
		i++;
	}
}

void	v_draw_grid_v(t_v *v)
{
	int		i;
	t_coord dist;
	t_coord pos;

	i = 0;
	dist.y = v->sq_s * v->map_s.y;
	pos.x = 0;
	while (i <= v->map_s.x)
	{
		pos.y = v->of.y;
		while (pos.y <= dist.y + v->of.y)
		{
			draw_pixel(pos.y, pos.x, v, C_GRID);
			draw_pixel(pos.y, pos.x - 1, v, C_GRID);
			draw_pixel(pos.y, pos.x + 1, v, C_GRID);
			pos.y++;
		}
		pos.x += v->sq_s;
		i++;
	}
}

void	v_draw_grids(t_v *v)
{
	v_draw_grid_h(v);
	v_draw_grid_v(v);
}
