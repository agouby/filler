/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:00:57 by agouby            #+#    #+#             */
/*   Updated: 2016/11/14 13:02:36 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_split		ft_getwords(char const *str, size_t start, int c)
{
	size_t	len;
	t_split split;

	len = 0;
	while (str[start] == c)
	{
		start++;
	}
	while (str[start + len] != c && str[start + len])
	{
		len++;
	}
	split.len = len;
	split.start = start;
	return (split);
}
