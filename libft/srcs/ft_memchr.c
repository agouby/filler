/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:23:17 by agouby            #+#    #+#             */
/*   Updated: 2016/11/14 13:05:39 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new;
	unsigned char	c_new;
	size_t			i;

	i = 0;
	c_new = (unsigned char)c;
	new = (unsigned char *)s;
	while (i < n)
	{
		if (new[i] == c_new)
			return (new + i);
		i++;
	}
	return (NULL);
}
