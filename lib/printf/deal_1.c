/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:52:41 by agouby            #+#    #+#             */
/*   Updated: 2017/03/07 23:53:03 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_width(t_flags *flags, t_infos *infos)
{
	infos->len_arg = (int)ft_strlen(flags->arg_str);
	if (infos->len_arg >= 0 && infos->w_flag - infos->len_arg > 0)
	{
		if (!infos->zero_flag)
			infos->infos_str =
				ft_strnew_set(infos->w_flag - (infos->len_arg), ' ');
		else
			infos->infos_str =
				ft_strnew_set(infos->w_flag - (infos->len_arg), '0');
		if (infos->min_flag)
			flags->arg_str =
				ft_strjoin_del(flags->arg_str, infos->infos_str, 0);
		else
			flags->arg_str =
				ft_strjoin_del(infos->infos_str, flags->arg_str, 0);
	}
}

void	deal_with_s(t_flags *flags, t_infos *infos)
{
	if ((infos->pstar && infos->prec_flag == 0) ||
			(infos->wrong_prec && !infos->pstar))
		*flags->arg_str = '\0';
	if (infos->prec_flag)
	{
		if (infos->prec_flag > 0)
			flags->arg_str = ft_strsub(flags->arg_str, 0, infos->prec_flag);
	}
	if (infos->w_flag)
		apply_width(flags, infos);
}

void	deal_with_sw(t_flags *flags, t_infos *infos)
{
	int i;
	int n;
	int cut;

	cut = infos->prec_flag;
	n = 0;
	i = 0;
	if (infos->wrong_prec)
		*flags->arg_str = '\0';
	if (!flags->wtmp)
		return ;
	while (flags->wtmp[i] != '\0' && cut >= get_charlen(flags->wtmp[i]))
	{
		n += get_charlen(flags->wtmp[i]);
		cut -= get_charlen(flags->wtmp[i]);
		i++;
	}
	if (infos->prec_flag)
	{
		if (infos->prec_flag > 0)
			flags->arg_str = ft_strsub(flags->arg_str, 0, n);
	}
	if (infos->w_flag)
		apply_width(flags, infos);
}

void	deal_with_b(char type, t_flags *flags)
{
	int len;

	len = (int)ft_strlen(flags->arg_str);
	if (len % 8 > 4)
		len = 4 - len % 4;
	else
		len = 8 - len % 8;
	if (len % 8)
		flags->arg_str =
			ft_strjoin_del(ft_strnew_set(len, '0'), flags->arg_str, 0);
	if (type == 'B')
		reverse_bits(flags->arg_str);
	flags->arg_str = add_space_b(flags->arg_str);
}

void	deal_with_notype(t_flags *flags, t_infos *infos)
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
