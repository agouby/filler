/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:24:10 by agouby            #+#    #+#             */
/*   Updated: 2017/03/22 12:25:26 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	update_dir(t_fill *fill, t_play *play)
{
	get_direction(play);
	get_quarter(fill, &play->me);
	get_quarter(fill, &play->op);
	change_dir(play);
}
