/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:55:51 by agouby            #+#    #+#             */
/*   Updated: 2017/03/12 05:45:47 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (*big)
	{
		i = 0;
		while (little[i] == *(big + i))
		{
			if (little[i + 1] == '\0')
				return ((char *)big);
			i++;
		}
		big++;
	}
	return (NULL);
}
