/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:52:55 by agouby            #+#    #+#             */
/*   Updated: 2017/03/09 02:53:40 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_width(char type, t_flags *f, t_infos *i)
{
	if (i->w_flag && i->w_flag - i->len_arg > 0)
	{
		i->len_arg = (int)ft_strlen(f->arg_str);
		{
			if (i->zero_flag)
				deal_with_zero(type, f, i);
			else if (type != 'p')
				i->infos_str = ft_strnew_set(i->w_flag - (i->len_arg), ' ');
			else if (type == 'p' && f->arg_num)
				i->infos_str = ft_strnew_set(i->w_flag - (i->len_arg), ' ');
			else
				i->infos_str = ft_strnew_set(i->w_flag - (i->len_arg) - 2, ' ');
			if (type == 'p' && f->arg_num == 0 && !i->zero_flag && !i->min_flag)
				i->infos_str = ft_strjoin_del(i->infos_str, "0x", 1);
			if (type == 'p' && f->arg_num == 0 && !i->zero_flag && i->min_flag)
				i->infos_str = ft_strjoin_del("0x", i->infos_str, 2);
			if (i->min_flag)
				f->arg_str = ft_strjoin_del(f->arg_str, i->infos_str, 0);
			else
				f->arg_str = ft_strjoin_del(i->infos_str, f->arg_str, 0);
		}
	}
}

void	deal_with_digit(char type, t_flags *flags, t_infos *infos)
{
	deal_with_prec_d(flags, infos);
	if (arg_is_signed(type) && flags->arg_num < 0)
		flags->arg_str = ft_strjoin_del("-", flags->arg_str, 2);
	add_type_front(type, flags, infos);
	deal_with_width(type, flags, infos);
	if (type == 'p' && flags->arg_num == 0 &&
			!infos->zero_flag && !infos->w_flag)
		flags->arg_str = ft_strjoin_del("0x", flags->arg_str, 2);
	if (type == 'p' && flags->arg_num == 0 &&
			!infos->zero_flag && infos->min_flag)
		ft_swapc(&flags->arg_str[1], &flags->arg_str[2]);
	if (type == 'X')
		flags->arg_str = ft_strtoupper(flags->arg_str);
}

int		deal_with_char(t_flags *f, t_infos *i)
{
	char cpy;

	cpy = *f->arg_str;
	if (i->w_flag)
	{
		if (!i->zero_flag)
			i->infos_str = ft_strnew_set(i->w_flag - 1, ' ');
		else
			i->infos_str = ft_strnew_set(i->w_flag - 1, '0');
		if (i->min_flag)
			f->arg_str = ft_strjoin_del(f->arg_str, i->infos_str, 0);
		else
			f->arg_str = ft_strjoin_del(i->infos_str, f->arg_str, 0);
	}
	if (cpy == 0)
	{
		f->arg_str = ft_strjoin_del(f->arg_str, " ", 1);
		if (i->is_min != 1)
			i->pos_bz = ft_strlen(f->format_tmp) + ft_strlen(f->arg_str);
		else
			i->pos_bz = ft_strlen(f->format_tmp) + 1;
		return (1);
	}
	return (0);
}

void	deal_with_perc(t_flags *flags, t_infos *infos)
{
	if (infos->w_flag)
	{
		if (infos->zero_flag)
			infos->infos_str =
				ft_strnew_set(infos->w_flag - (infos->len_arg), '0');
		else
			infos->infos_str =
				ft_strnew_set(infos->w_flag - (infos->len_arg), ' ');
		if (infos->min_flag)
			flags->arg_str =
				ft_strjoin_del(flags->arg_str, infos->infos_str, 0);
		else
			flags->arg_str =
				ft_strjoin_del(infos->infos_str, flags->arg_str, 0);
	}
}

int		deal_with_cw(t_flags *flags, t_infos *infos)
{
	if (*flags->arg_str == 0)
	{
		flags->format_tmp = ft_strjoin(flags->format_tmp, " ");
		infos->pos_bz = ft_strlen(flags->format_tmp);
		return (1);
	}
	return (0);
}
