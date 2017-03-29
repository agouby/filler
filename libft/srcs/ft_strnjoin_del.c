/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:38:09 by agouby            #+#    #+#             */
/*   Updated: 2017/01/22 19:49:18 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_del(char const *s1, char const *s2, int s, int e)
{
	char		*new;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s1) + (e - s))))
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s < e)
	{
		new[i + j] = s2[s];
		s++;
		j++;
	}
	new[i + j] = '\0';
	ft_strdel((char **)&s1);
	ft_strdel((char **)&s2);
	return (new);
}
