/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:14:11 by agouby            #+#    #+#             */
/*   Updated: 2016/11/14 13:09:35 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sorts(char **s, size_t start, size_t len)
{
	int		swapped;
	size_t	start2;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		start2 = start;
		while (start2 < len)
		{
			if (ft_strcmp(s[start2 - 1], s[start2]) > 0)
			{
				ft_swaps(&s[start2], &s[start2 - 1]);
				swapped = 1;
			}
			else
				start2++;
		}
	}
	return (s);
}
