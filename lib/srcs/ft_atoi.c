/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:36:27 by agouby            #+#    #+#             */
/*   Updated: 2017/03/08 00:26:51 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long coef;
	long nb;

	nb = 0;
	coef = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		coef = -1;
	}
	while (ft_isdigit(*str))
	{
		nb = (*str - '0') + nb * 10;
		str++;
	}
	return (nb * coef);
}
