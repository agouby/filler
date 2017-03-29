/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:25:01 by agouby            #+#    #+#             */
/*   Updated: 2016/11/14 13:16:39 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	size_t len;

	len = ft_strlen(str);
	while (*str)
	{
		if (ft_isupper(*str))
			*str += 32;
		str++;
	}
	return (str - len);
}
