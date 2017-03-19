/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:54:40 by agouby            #+#    #+#             */
/*   Updated: 2017/03/16 18:33:36 by agouby           ###   ########.fr       */
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
	t_coord	next;
}				t_player;

typedef struct	s_fill
{
	char		**map;
	int		**d_tab;
	int		oc;
	int		xc;
	int		nb_pos;
	t_coord		map_s;
	t_coord		pie_s;
	char		**piece;
}				t_fill;

typedef	struct	s_help
{
	int		tmp_dist;
	int		next_dist;
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
	char		dir[3];
}				t_play;

void			filler(void);
void			init_structs(t_fill *fill, t_play *play);
void			print_map(char **map);
void			print_piece(char **piece);
void			get_player(int fd, char *line, t_play *play);
void			get_size(int fd, char *line, t_fill *fill);
void			create_map(int fd, t_fill *fill);
void			store_infos(int fd, t_fill *fill, t_play *play);
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
void			change_and_count(t_fill *fill, char **line);
int			is_overlap(t_fill *fill, t_play *play);

/*
**	TO DELETE 
*/

void			print_dist(t_fill *fill);

#endif
