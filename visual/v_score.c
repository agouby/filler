/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_score.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:29:41 by agouby            #+#    #+#             */
/*   Updated: 2017/03/28 05:40:51 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"


#include <stdio.h>

void	v_draw_bk(t_v *v)
{
	t_coord i;
	int ytmp;

	i.y = (1000 - (v->map_s.y * v->sq_s)) / 2 + 20;
	while (i.y < v->of.y + (v->map_s.y * v->sq_s) - 20)
	{
		i.x = 1190;
		while (i.x < 1405)
		{
			draw_pixel(i.y, i.x, v, 0x424242);
			i.x++;
		}
		i.y++;
	}
}

void	v_draw_green(t_v *v)
{
	t_coord i;
	t_coord tmp;

	i.y = 1000 - v->of.y - 10;
	if (v->p1.nb_pos > v->p2.nb_pos)
		i.x = 1240;
	else if (v->p1.nb_pos < v->p2.nb_pos)
		i.x = 1340;
	else
		i.x = 1293;
	tmp.y = i.y;
	tmp.x = i.x;
	while (i.y < tmp.y + 10)
	{
		i.x = tmp.x;
		while (i.x < tmp.x + 10)
		{
			draw_pixel(i.y, i.x, v, 0xFFFF00);
			i.x++;
		}
		i.y++;
	}
}

void	v_draw_score_nb(t_v *v)
{
	char *p1;
	char *p2;
	char *join;
	
	join = NULL;
	if (v->p1.nb_pos < 10)
		join = "000";
	else if (v->p1.nb_pos < 100)
		join = "00";
	else if (v->p1.nb_pos < 1000)
		join = "0";
	p1 = ft_itoa_base(v->p1.nb_pos, 10);
	if (join)
		p1 = ft_strjoin_del(join, p1, 2);
	mlx_string_put(v->mlx, v->win, 1145,  1000 - v->of.y - 25 - v->p1.fac, v->p1.color, p1);
	mlx_string_put(v->mlx, v->win, 1185 - ft_strlen(v->p1.name) * 10, HEIGHT - v->of.y - 45 - v->p1.fac, v->p1.color, v->p1.name);
	join = NULL;
	if (v->p2.nb_pos < 10)
		join = "000";
	else if (v->p2.nb_pos < 100)
		join = "00";
	else if (v->p2.nb_pos < 1000)
		join = "0";
	p2 = ft_itoa_base(v->p2.nb_pos, 10);
	if (join)
		p2 = ft_strjoin_del(join, p2, 2);
	mlx_string_put(v->mlx, v->win, 1410,  1000 - v->of.y - 25 - v->p2.fac, v->p2.color, p2);
	mlx_string_put(v->mlx, v->win, 1410, 1000 - v->of.y - 45 - v->p2.fac, v->p2.color, v->p2.name);
}

void	v_draw_score(t_v *v, t_p *p)
{
	t_coord	i;
	int		x_r;
	int		color;

	v->full_nb_pos = v->map_s.y * v->map_s.x;
	p->fac = ((v->map_s.y * v->sq_s - 50) / v->full_nb_pos) * p->nb_pos;
	if (p->c == 'O')
		i.x = 1195;
	else
		i.x = 1300;
	x_r = i.x;
	i.y = (1000 - (v->map_s.y * v->sq_s)) / 2 + 25;
	while (i.y < v->of.y + (v->map_s.y * v->sq_s) - 25)
	{
		color = p->color;
		i.x = x_r;
		if (i.y <= v->of.y + (v->map_s.y * v->sq_s - 25) - p->fac)
			color = v->bk_color;
		while (i.x < x_r + 100)
		{
			draw_pixel(i.y, i.x, v, color);
			i.x++;
		}
		i.y++;
	}
	v_draw_green(v);
}
