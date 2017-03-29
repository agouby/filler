/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 20:21:31 by agouby            #+#    #+#             */
/*   Updated: 2017/01/23 20:28:53 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_set(size_t size, char set)
{
	char *new;

	new = ft_strnew(size);
	ft_memset((char *)new, set, size);
	return (new);
}
