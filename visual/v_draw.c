/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:40:54 by agouby            #+#    #+#             */
/*   Updated: 2017/03/29 01:17:35 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	get_square_size(t_v *v)
{
	if (v->map_s.y > v->map_s.x)
		v->sq_s = (HEIGHT / v->map_s.y);
	else
		v->sq_s = (HEIGHT / v->map_s.x);
	v->of.y = (HEIGHT - (v->sq_s * v->map_s.y)) / 2;
	v->of.x = (HEIGHT - (v->sq_s * v->map_s.x)) / 2;
}

void	get_color(char letter, int *color)
{
	if (ft_toupper(letter) == 'O')
		*color = C_P1;
	else if (ft_toupper(letter) == 'X')
		*color = C_P2;
	else
		*color = C_BK_M;
}

void	draw_square(t_v *v, int y, int x, int color)
{
	t_coord i;

	i.y = 0;
	while (i.y <= v->sq_s)
	{
		i.x = 0;
		while (i.x <= v->sq_s)
		{
			draw_pixel(y + i.y, x + i.x, v, color);
			i.x++;
		}
		i.y++;
	}
}

void	v_draw_all_squares(t_v *v)
{
	t_coord i;
	t_coord p;
	int		color;

	i.y = 0;
	color = 0;
	p.y = v->of.y;
	get_square_size(v);
	while (v->map[i.y])
	{
		p.x = 0;
		i.x = 0;
		while (v->map[i.y][i.x])
		{
			get_color(v->map[i.y][i.x], &color);
			draw_square(v, p.y, p.x, color);
			p.x += v->sq_s;
			i.x++;
		}
		i.y++;
		p.y += v->sq_s;
	}
}
