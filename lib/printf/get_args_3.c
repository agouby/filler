/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:22:00 by agouby            #+#    #+#             */
/*   Updated: 2017/03/06 19:22:06 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_conversion(char type)
{
	if (type == 'o' || type == 'O')
		return (8);
	else if (type == 'x' || type == 'X' || type == 'p')
		return (16);
	return (10);
}

void	get_star(t_infos *infos, char *str_flag)
{
	while (*str_flag)
	{
		if (*str_flag == '.' && *(str_flag + 1) == '*')
		{
			infos->pstar = 1;
			str_flag++;
		}
		else if (*str_flag == '*')
		{
			infos->wstar = 1;
			infos->w_flag = 0;
		}
		str_flag++;
	}
}
