/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:42:29 by agouby            #+#    #+#             */
/*   Updated: 2016/11/14 13:09:24 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int	*tab;

	if (min >= max)
		return (NULL);
	tab = (int *)ft_memalloc(sizeof(int) * (max - min));
	while (min < max)
	{
		*tab = min;
		tab++;
		min++;
	}
	return (tab);
}
