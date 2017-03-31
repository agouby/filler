/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 01:07:29 by agouby            #+#    #+#             */
/*   Updated: 2017/03/31 05:00:01 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	v_init_coord(t_coord *i)
{
	i->x = 0;
	i->y = 0;
}

void	v_init_p(t_p *p)
{
	p->c = 0;
	p->fac = 0;
	p->nb_pos = 0;
	p->name = "no player";
}

void	v_init(t_v *v)
{
	v->mlx = NULL;
	v->win = NULL;
	v->img = NULL;
	v->pixel_img = NULL;
	v->bpp = 0;
	v->s_line = 0;
	v->ed = 0;
	v->sq_s = 0;
	v->full_nb_pos = 0;
	v->map = NULL;
	v_init_coord(&v->map_s);
	v_init_coord(&v->of);
	v_init_coord(&v->i);
	v_init_p(&v->p1);
	v_init_p(&v->p2);
}
