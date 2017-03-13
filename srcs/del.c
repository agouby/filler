/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 06:58:06 by agouby            #+#    #+#             */
/*   Updated: 2017/03/13 08:55:13 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	del_arrays(t_fill *fill)
{
	size_t i;

	i = 0;
	while (i < fill->m.y)
		free(fill->map[i++]);
	free(fill->map);
	i = 0;
	while (i < fill->p.y)
		free(fill->piece[i++]);
	free(fill->piece);
}
