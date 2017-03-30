/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touched.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 23:33:03 by agouby            #+#    #+#             */
/*   Updated: 2017/03/30 09:51:25 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_touched(t_fill *f, t_play *p, t_coord i)
{
	t_coord p_tmp;

	p_tmp.y = p->pie_pos.y + i.y;
	p_tmp.x = p->pie_pos.x + i.x;
	if (p_tmp.x + 5 >= f->map_s.x || p_tmp.x + 3 < 4 ||
		p_tmp.y + 1 >= f->map_s.y || p_tmp.y - 1 < 0)
		return ;
	if (f->map[p_tmp.y][p_tmp.x + 5] == p->op.c)
		p->touched = 1;
	else if (f->map[p_tmp.y][p_tmp.x + 3] == p->op.c)
		p->touched = 1;
	else if (f->map[p_tmp.y + 1][p_tmp.x + 4] == p->op.c)
		p->touched = 1;
	else if (f->map[p_tmp.y - 1][p_tmp.x + 4] == p->op.c)
		p->touched = 1;
}
