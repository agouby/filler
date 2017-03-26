/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:41:29 by agouby            #+#    #+#             */
/*   Updated: 2017/03/26 06:41:29 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	chk_dir_u(t_fill *fill, t_play *play, char *(*f)(const char *, int))
{
	int		i;
	char	*s;

	s = NULL;
	i = fill->pie_s.y - 1;
	while (!(s = f(fill->piece[i], '*')))
		i--;
	play->pie_pos.y = i;
	play->pie_pos.x = s - fill->piece[i];
}

void	chk_dir_d(t_fill *fill, t_play *play, char *(*f)(const char *, int))
{
	int		i;
	char	*s;

	s = NULL;
	i = 0;
	while (!(s = f(fill->piece[i], '*')))
		i++;
	play->pie_pos.y = i;
	play->pie_pos.x = s - fill->piece[i];
}
