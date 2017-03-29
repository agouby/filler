/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_score.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:29:41 by agouby            #+#    #+#             */
/*   Updated: 2017/03/29 01:17:55 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	v_draw_bk(t_v *v)
{
	t_coord i;

	i.y = (HEIGHT - (v->map_s.y * v->sq_s)) / 2 + 20;
	while (i.y < v->of.y + (v->map_s.y * v->sq_s) - 20)
	{
		i.x = 1190;
		while (i.x < 1405)
		{
			draw_pixel(i.y, i.x, v, C_BK_S);
			i.x++;
		}
		i.y++;
	}
}

void	v_draw_dot(t_v *v)
{
	t_coord i;
	t_coord tmp;

	i.y = HEIGHT - v->of.y - 10;
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

char	*v_join_score_nb(t_p *p)
{
	char *join;
	char *res;

	join = NULL;
	if (p->nb_pos < 10)
		join = "000";
	else if (p->nb_pos < 100)
		join = "00";
	else if (p->nb_pos < HEIGHT)
		join = "0";
	res = ft_itoa_base(p->nb_pos, 10);
	if (join)
		res = ft_strjoin_del(join, res, 2);
	return (res);
}

void	v_draw_score_nb(t_v *v)
{
	char *p1;
	char *p2;

	p1 = v_join_score_nb(&v->p1);
	mlx_string_put(v->mlx, v->win, 1145, HEIGHT - v->of.y - 25 - v->p1.fac,
			C_P1, p1);
	mlx_string_put(v->mlx, v->win, 1185 - ft_strlen(v->p1.name) * 10,
			HEIGHT - v->of.y - 45 - v->p1.fac, C_P1, v->p1.name);
	p2 = v_join_score_nb(&v->p2);
	mlx_string_put(v->mlx, v->win, 1410, HEIGHT - v->of.y - 25 - v->p2.fac,
			C_P2, p2);
	mlx_string_put(v->mlx, v->win, 1410, HEIGHT - v->of.y - 45 - v->p2.fac,
			C_P2, v->p2.name);
}

void	v_draw_score(t_v *v, t_p *p, int color_p)
{
	t_coord	i;
	int		x_r;
	int		color;

	v->full_nb_pos = v->map_s.y * v->map_s.x;
	p->fac = ((v->map_s.y * v->sq_s - 50) / v->full_nb_pos) * p->nb_pos;
	i.x = (p->c == 'O') ? 1195 : 1300;
	x_r = i.x;
	i.y = v->of.y + 25;
	while (i.y < v->of.y + (v->map_s.y * v->sq_s) - 25)
	{
		color = color_p;
		i.x = x_r;
		if (i.y <= v->of.y + (v->map_s.y * v->sq_s - 25) - p->fac)
			color = C_BK_M;
		while (i.x < x_r + 100)
		{
			draw_pixel(i.y, i.x, v, color);
			i.x++;
		}
		i.y++;
	}
	v_draw_dot(v);
}
