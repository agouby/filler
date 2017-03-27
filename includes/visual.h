/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:51:05 by agouby            #+#    #+#             */
/*   Updated: 2017/03/27 21:04:06 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "ft_printf.h"
# include "filler.h"
# include <mlx.h>

# define WIDTH	2000
# define HEIGHT 1000
# define ESC_M	53
# define ESC_L	65307
# define SP_L	32
# define SP_M	49

typedef struct	s_v
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*pixel_img;
	int		bpp;
	int		s_line;
	int		ed;
	int		sq_s;
	int		nb_pos;
	int		nb_pos_m;
	int		nb_pos_o;
	char	me;
	char	him;
	char	**map;
	t_coord	map_s;
}				t_v;

void	v_create_win(t_v *v);
void	create_win(t_v *v);
int		v_key_hook(int key, t_v *v);
void	v_parse_file(t_v *v);
void	v_draw_all_squares(t_v *v);
void	v_init(t_v *v);
void	draw_pixel(int y, int x, t_v *v, int color);

void	v_draw_score_bk(t_v *v);
//void	reload(t_v *v);

#endif
