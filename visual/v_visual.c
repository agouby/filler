/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_visual.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 01:08:17 by agouby            #+#    #+#             */
/*   Updated: 2017/03/30 11:21:52 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		v_loop(t_v *v)
{
	v->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	v->pixel_img = mlx_get_data_addr(v->img, &(v->bpp), &(v->s_line), &(v->ed));
	v_parse_file(v);
	v_draw_all_squares(v);
	v_draw_grids(v);
	v_draw_bk(v);
	v_draw_score(v, &v->p1, C_P1);
	v_draw_score(v, &v->p2, C_P2);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	v_draw_score_nb(v);
	mlx_destroy_image(v->mlx, v->img);
	return (0);
}

int		main(void)
{
	t_v v;

	v_init(&v);
	v_create_win(&v);
	mlx_hook(v.win, 2, 3, v_key_hook, &v);
	mlx_loop_hook(v.mlx, v_loop, (t_v *)&v);
	mlx_loop(v.mlx);
	return (0);
}
