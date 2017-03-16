/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:54:40 by agouby            #+#    #+#             */
/*   Updated: 2017/03/16 11:27:40 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_printf.h"

/*
** DELETE INCLUDES BELOW
*/

# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef	struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_player
{
	char	m;
	char	o;
}				t_player;

typedef struct	s_fill
{
	char		**map;
	t_coord		map_s;
	t_coord		pie_s;
	t_player	player;
	char		**piece;
}				t_fill;

typedef	struct	s_play
{
	t_coord	pos_o;
	t_coord pos_m;
	t_coord	first_o;
	t_coord	first_m;
	t_coord last_o;
	t_coord last_m;
	t_coord next_o;
	t_coord next_m;
	char	dir[2];
}				t_play;

typedef	struct	s_help
{
	int		tmp_dist;
	int		small_dist;
	t_coord	pos_o_saved;
	t_coord	pos_m_saved;
}				t_help;

void	filler(void);
void	init_structs(t_fill *, t_play *, t_help *);
void	print_map(char **);
void	print_piece(char **);
void	get_player(int, char *, t_fill *);
void	get_size(int, char *, t_fill *);
void	create_map(int, t_fill *);
void	store_infos(int, t_fill *);
void	jump_lines(int, char *, size_t);
void	create_piece(int, char *, t_fill *);
void	del_arrays(t_fill *fill);
void	get_closest_pos(t_fill *fill, t_play *play, t_help *help);
void	get_direction(t_play *flay);
void	init_coord(t_coord *co);
void	calculate_dist(t_play *play, t_help *help);
void	get_dist(t_fill *fill, t_play *play, t_help *help);
void	get_next_pos_o(t_fill *fill, t_play *play);
void	get_next_pos_m(t_fill *fill, t_play *play);

#endif
