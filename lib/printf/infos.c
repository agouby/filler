/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:27:50 by agouby            #+#    #+#             */
/*   Updated: 2017/03/03 00:55:36 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_wrong_prec(t_infos *infos)
{
	infos->wrong_prec = 1;
	return ;
}

static void		get_precision(t_infos *infos, char *str_flag)
{
	while (*str_flag)
	{
		if (*str_flag == '.')
		{
			while (*str_flag == '.')
				str_flag++;
			if (!ft_isdigit(*str_flag))
				set_wrong_prec(infos);
			while (*str_flag == '0')
				str_flag++;
			if (ft_isdigit(*str_flag))
				infos->prec_flag = ft_atoi(str_flag);
			else
				set_wrong_prec(infos);
			while (ft_isdigit(*str_flag))
				str_flag++;
			if (*str_flag == '.')
			{
				infos->prec_flag = 1;
				return ;
			}
		}
		str_flag++;
	}
}

static void		get_width(t_infos *infos, char *str_flag)
{
	while (*str_flag && !ft_isdigit(*str_flag))
	{
		if (*(str_flag + 1) == '0' && *str_flag != '.')
		{
			infos->zero_flag = 1;
			while (*(str_flag + 1) == '0')
				str_flag++;
		}
		if (*str_flag == '.')
			return ;
		str_flag++;
	}
	if (*str_flag == '0')
	{
		infos->zero_flag = 1;
		str_flag++;
	}
	while (!ft_isdigit(*str_flag) && *str_flag && *str_flag != '.')
		str_flag++;
	infos->w_flag = ft_atoi(str_flag);
}

static void		get_other_infos(t_infos *infos, char *str_flag)
{
	while (*str_flag)
	{
		if (*str_flag == '#')
			infos->hash_flag = 1;
		else if (*str_flag == '-')
			infos->min_flag = 1;
		else if (*str_flag == '+')
			infos->plus_flag = 1;
		else if (*str_flag == ' ')
			infos->sp_flag = 1;
		else if (*str_flag == 'l' && *(str_flag + 1) != 'l')
			infos->l_flag = 1;
		else if (*str_flag == 'l' && *(str_flag + 1) == 'l' && str_flag++)
			infos->ll_flag = 1;
		else if (*str_flag == 'h' && *(str_flag + 1) != 'h')
			infos->h_flag = 1;
		else if (*str_flag == 'h' && *(str_flag + 1) == 'h' && str_flag++)
			infos->hh_flag = 1;
		else if (*str_flag == 'j')
			infos->j_flag = 1;
		else if (*str_flag == 'z')
			infos->z_flag = 1;
		str_flag++;
	}
}

void			get_infos(t_infos *infos, char *str_flag)
{
	if (!str_flag)
		return ;
	init_infos(infos);
	get_star(infos, str_flag);
	get_width(infos, str_flag);
	get_precision(infos, str_flag);
	get_other_infos(infos, str_flag);
}
