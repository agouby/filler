/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:54:40 by agouby            #+#    #+#             */
/*   Updated: 2017/03/13 08:55:11 by agouby           ###   ########.fr       */
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
	size_t	x;
	size_t	y;
}				t_coord;

typedef struct	s_fill
{
	char	**map;
	t_coord	m;
	t_coord	p;
	char	player_m;
	char	player_o;
	char	**piece;
}				t_fill;

typedef	struct	s_play
{
	t_coord	o_start;
	t_coord	m_start;
}				t_play;

void	filler(void);
void	init_structs(t_fill **, t_play **);
void	print_map(char **);
void	print_piece(char **);
void	get_player(int, char *, t_fill *);
void	get_size(int, char *, t_fill *);
void	create_map(int, t_fill *);
void	store_infos(int, t_fill *);
void	jump_lines(int, char *, size_t);
void	create_piece(int, char *, t_fill *);
void	del_arrays(t_fill *fill);
void	get_first_pos(t_fill *fill, t_play *play);

#endif
