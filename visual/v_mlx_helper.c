/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_mlx_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:43:10 by agouby            #+#    #+#             */
/*   Updated: 2018/01/16 06:00:56 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	v_create_win(t_v *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIDTH, HEIGHT, "Filler by agouby");
}

void	draw_pixel(int y, int x, t_v *v, int color)
{
	int i;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	i = (x * 4) + (y * v->s_line);
	v->pixel_img[i] = color;
	v->pixel_img[++i] = color >> 8;
	v->pixel_img[++i] = color >> 16;
}
