/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:18:30 by agouby            #+#    #+#             */
/*   Updated: 2017/03/29 01:43:39 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_jump_lines(int fd, char *line, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n)
	{
		get_next_line(fd, &line);
		ft_strdel(&line);
	}
}
