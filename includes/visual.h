/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:51:05 by agouby            #+#    #+#             */
/*   Updated: 2017/03/30 11:23:24 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "ft_printf.h"
# include "filler.h"
# include <mlx.h>

# define WIDTH	1600
# define HEIGHT 1000
# define ESC_M	53
# define ESC_L	65307
# define SP_L	32
# define SP_M	49
# define C_BK_S 0xC9C9C9
# define C_BK_M	0x363636
# define C_GRID 0x141414
# define C_P1	0xFF2200
# define C_P2	0x0072FF

typedef struct	s_p
{
	int		nb_pos;
	char	*name;
	char	c;
	double	fac;
}				t_p;

typedef struct	s_v
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*pixel_img;
	int		bpp;
	int		s_line;
	int		ed;
	t_coord	of;
	double	sq_s;
	t_p		p1;
	t_p		p2;
	t_coord i;
	int		full_nb_pos;
	char	**map;
	t_coord	map_s;
}				t_v;

void			v_create_win(t_v *v);
int				v_key_hook(int key, t_v *v);
void			v_parse_file(t_v *v);
void			v_draw_all_squares(t_v *v);
void			v_draw_grids(t_v *v);
void			v_init(t_v *v);
void			draw_pixel(int y, int x, t_v *v, int color);
void			v_draw_bk(t_v *v);
void			v_draw_score(t_v *v, t_p *p, int color);
void			v_draw_score_nb(t_v *v);

#endif
