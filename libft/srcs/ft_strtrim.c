/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:17:57 by agouby            #+#    #+#             */
/*   Updated: 2016/11/14 13:16:55 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s_temp;

	if (!s || !(s_temp = ft_strdup((char *)s)))
		return (NULL);
	while (ft_isspace(*s_temp))
		s_temp++;
	s_temp = ft_strrev(s_temp);
	while (ft_isspace(*s_temp))
		s_temp++;
	s_temp = ft_strrev(s_temp);
	if (!(s_temp = ft_strdup(s_temp)))
		return (NULL);
	return (s_temp);
}
