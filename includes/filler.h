/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:54:40 by agouby            #+#    #+#             */
/*   Updated: 2017/03/25 05:54:10 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_printf.h"

/*
** DELETE INCLUDES BELOW
*/

# include <fcntl.h>

typedef	struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_player
{
	char	c;
	char	quart[3];
	t_coord	pos;
	t_coord	first;
	t_coord	last;
	t_coord	tmp;
	t_coord	tmp2;
	t_coord	next;
}				t_player;

typedef struct	s_fill
{
	char		**map;
	int			oc;
	int			xc;
	int			nb_pos;
	t_coord		map_s;
	t_coord		pie_s;
	char		**piece;
}				t_fill;

typedef	struct	s_help
{
	int		tmp_dist;
	int		small_dist;
	t_coord	pos_o_saved;
	t_coord	pos_m_saved;
}				t_help;

typedef	struct	s_play
{
	t_player	op;
	t_player	me;
	t_coord		pie_pos;
	t_coord		pie_len;
	t_help		help;
	int			touched;
	int			cnt;
	char		dir[3];
}				t_play;

void			filler(void);
void			init_structs(t_fill *fill, t_play *play);
void			print_map(char **map);
void			print_piece(char **piece);
void			get_player(int fd, t_play *play);
void			get_size(int fd, char *line, t_fill *fill);
void			create_map(int fd, int fd_vis, t_fill *fill);
void			store_infos(int fd, int fd_vis, t_fill *fill);
void			jump_lines(int fd, char *line, size_t i);
void			create_piece(int fd, char *line, t_fill *fill);
void			del_arrays(t_fill *fill);
void			get_closest_pos(t_fill *fill, t_play *play);
void			get_direction(t_play *flay);
void			init_coord(t_coord *co);
void			get_dist(t_fill *fill, t_play *play);
void			get_next_pos(t_fill *fill, t_player *player);
void			end_next_pos(t_player *player);
void			get_piece(t_fill *fill, t_play *play);
void			get_quarter(t_fill *fill, t_player *player);
void			count_pos(t_fill *fill, char **line);
int				is_overlap(t_fill *fill, t_play *play);
void			get_next_dist(t_fill *fill, t_play *play);
void			store_all_dist(t_fill *fill, t_play *play);
void			update_dir(t_fill *fill, t_play *play);
void			change_dir(t_play *play);
void			chk_dir_u(t_fill *f, t_play *p, char *(*ft)(const char *, int));
void			chk_dir_d(t_fill *f, t_play *p, char *(*ft)(const char *, int));

/*
**	TO DELETE
*/

void			print_dist(t_fill *fill);
void			print_piece_map(t_fill *fill, t_play *play);

#endif
