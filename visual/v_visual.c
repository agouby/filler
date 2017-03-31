/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_visual.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 01:08:17 by agouby            #+#    #+#             */
/*   Updated: 2017/03/31 05:07:40 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		v_loop(t_v *v)
{
	v->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	v->pixel_img = mlx_get_data_addr(v->img, &(v->bpp), &(v->s_line), &(v->ed));
	v_read_stdin(v);
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

void	check_for_errors(char *line)
{
	if (ft_strstr(line, "./visual.fx"))
		ft_print_error("Error. Do not take the visualiser as a player.");
	else if (ft_strstr(line, "error") || ft_strstr(line, "Usage")
			|| ft_strstr(line, "the map is too small"))
		ft_print_error("Error. The map is too small.");
}

void	v_get_first_read(t_v *v)
{
	char *line;

	while (get_next_line(0, &line))
	{
		check_for_errors(line);
		if (ft_strstr(line, "$$$"))
			v_get_player(v, line);
		else if (ft_strstr(line, "Plateau"))
		{
			v_get_size_map(v, line);
			v->map = (char **)malloc(sizeof(char *) * (v->map_s.y + 1));
			v_get_map(v, line);
		}
		else if (ft_strstr(line, "Piece"))
		{
			ft_strdel(&line);
			return ;
		}
		else
			ft_strdel(&line);
	}
	if (v->map_s.y == 0 || v->map_s.x == 0)
		ft_print_error("Error. The VM stopped.");
}

int		main(void)
{
	t_v v;

	v_init(&v);
	v_get_first_read(&v);
	v_create_win(&v);
	mlx_hook(v.win, 2, 3, v_key_hook, &v);
	mlx_loop_hook(v.mlx, v_loop, (t_v *)&v);
	mlx_loop(v.mlx);
	return (0);
}
