/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 02:47:20 by agouby            #+#    #+#             */
/*   Updated: 2017/03/15 20:17:11 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_map(char **map)
{
	while (*map)
		ft_printf("%s\n", *map++);
}

void	print_piece(char **piece)
{
	while (*piece)
		ft_printf("%s\n", *piece++);
}
