/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:06:28 by agouby            #+#    #+#             */
/*   Updated: 2016/11/14 13:15:54 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t end;

	end = 0;
	i = 0;
	if (!*little)
		return ((char *)big);
	while (*big && end < len)
	{
		i = 0;
		while (little[i] == *(big + i) && end + ft_strlen(little) <= len)
		{
			if (little[i + 1] == '\0')
				return ((char *)big);
			i++;
		}
		end++;
		big++;
	}
	return (NULL);
}
