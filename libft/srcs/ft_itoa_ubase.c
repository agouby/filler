/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ubase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:46:26 by agouby            #+#    #+#             */
/*   Updated: 2017/03/12 06:00:22 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_count_udigit(unsigned long long n, int base)
{
	int count;

	count = 1;
	while (n >= (size_t)base)
	{
		n = n / base;
		count++;
	}
	return (count);
}

unsigned long long		ft_upower(unsigned long long n, int p)
{
	if (p < 0)
		return (0);
	else if (p == 0)
		return (1);
	else if (p < 2)
		return (n);
	else
		return (n *= ft_upower(n, p - 1));
	return (0);
}

char					*ft_itoa_ubase(unsigned long long n, int base)
{
	char					*str;
	size_t					i;
	unsigned long long		nb;
	char					*str_base;

	str_base = "0123456789abcdef";
	nb = ft_count_udigit(n, base);
	i = 0;
	if (!(str = ft_strnew(nb)))
		return (NULL);
	while (i < nb)
	{
		str[i] = str_base[n / ft_upower(base, nb - (i + 1)) % base];
		i++;
	}
	str[i] = '\0';
	return (str);
}
