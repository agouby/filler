/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:25:23 by agouby            #+#    #+#             */
/*   Updated: 2017/01/19 14:56:36 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	word;
	size_t	i;
	t_split	split;

	i = 0;
	if (!s || !c)
		return (NULL);
	word = ft_countwords((char *)s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	split = ft_getwords((char *)s, 0, c);
	while (i < word)
	{
		tab[i] = ft_strsub(s, split.start, split.len);
		split = ft_getwords(s, split.start + split.len, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
