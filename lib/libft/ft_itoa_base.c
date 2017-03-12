/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:46:26 by agouby            #+#    #+#             */
/*   Updated: 2017/03/12 06:00:49 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_digit(long long n, size_t base)
{
	int count;

	count = 1;
	while (n >= (long long)base)
	{
		n = n / base;
		count++;
	}
	return (count);
}

long long	ft_power(long long n, int p)
{
	if (p < 0)
		return (0);
	else if (p == 0)
		return (1);
	else if (p < 2)
		return (n);
	else
		return (n *= ft_power(n, p - 1));
	return (0);
}

char		*ft_itoa_base(long long n, int base)
{
	char	*str;
	long	i;
	long	nb;
	long	minus;
	char	*str_base;

	str_base = "0123456789abcdef";
	minus = 0;
	if (n < 0)
	{
		n = -n;
		minus = 1;
	}
	nb = ft_count_digit(n, base);
	i = 0;
	if (!(str = ft_strnew(nb + minus)))
		return (NULL);
	while (i < nb)
	{
		(minus == 1 && i == 0) ? str[i] = '-' : '\0';
		str[i + minus] = str_base[n / ft_power(base, nb - (i + 1)) % base];
		i++;
	}
	str[i + minus] = '\0';
	return (str);
}
