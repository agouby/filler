/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:06:19 by agouby            #+#    #+#             */
/*   Updated: 2017/02/01 17:03:06 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *new;

	new = (char *)s;
	if (c == '\0')
		return (new + ft_strlen(new));
	while (*new)
	{
		if (*new == (char)c)
			return (new);
		new++;
	}
	return (0);
}
