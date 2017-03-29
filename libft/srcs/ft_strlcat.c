/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:21:49 by agouby            #+#    #+#             */
/*   Updated: 2016/11/14 13:14:44 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dest_len;
	size_t j;

	dest_len = 0;
	j = 0;
	while (dst[dest_len] && dest_len < size)
		dest_len++;
	while (src[j] && dest_len + j < size - 1)
	{
		dst[dest_len + j] = src[j];
		j++;
	}
	if (dest_len < size)
		dst[dest_len + j] = '\0';
	return (dest_len + ft_strlen(src));
}
