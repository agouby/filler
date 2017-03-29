/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:06:19 by agouby            #+#    #+#             */
/*   Updated: 2017/03/14 13:15:42 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, int size)
{
	char *new;

	new = (char *)s;
	if (c == '\0' || size <= 0)
		return (new + ft_strlen(new));
	while (*new && size--)
	{
		if (*new == (char)c)
			return (new);
		new++;
	}
	return (0);
}
