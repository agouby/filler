/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:42:55 by agouby            #+#    #+#             */
/*   Updated: 2017/03/31 05:02:36 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		v_key_hook(int key, t_v *v)
{
	if (key == ESC_M)
	{
		ft_tab_del(v->map);
		if (!ft_strequ(v->p1.name, "no player"))
			free(v->p1.name);
		if (!ft_strequ(v->p2.name, "no player"))
			free(v->p2.name);
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	return (0);
}
