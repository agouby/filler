/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 02:54:40 by agouby            #+#    #+#             */
/*   Updated: 2017/03/13 03:20:32 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_printf.h"

/*
** DELETE INCLUDES BELOW
*/

# include <fcntl.h>

typedef struct	s_fill
{
	char	**map;
	size_t	x_s;
	size_t	y_s;
	size_t	player;
}				t_fill;

void	filler(void);
void	init_struct(t_fill **);
void	print_map(char **);
int		get_player(int, char *);
void	get_size(char *, size_t *, size_t *);
char	**create_map(int, size_t);
void	store_infos(t_fill *);

#endif
