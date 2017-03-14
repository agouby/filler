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

void	pr_deal_with_width(char type, t_prfgs *f, t_prinf *i)
{
	if (i->w_flag && i->w_flag - i->len_arg > 0)
	{
		i->len_arg = (int)ft_strlen(f->arg_str);
		{
			if (i->zero_flag)
				pr_deal_with_zero(type, f, i);
			else if (type != 'p')
				i->prinf_str = ft_strnew_set(i->w_flag - (i->len_arg), ' ');
			else if (type == 'p' && f->arg_num)
				i->prinf_str = ft_strnew_set(i->w_flag - (i->len_arg), ' ');
			else
				i->prinf_str = ft_strnew_set(i->w_flag - (i->len_arg) - 2, ' ');
			if (type == 'p' && f->arg_num == 0 && !i->zero_flag && !i->min_flag)
				i->prinf_str = ft_strjoin_del(i->prinf_str, "0x", 1);
			if (type == 'p' && f->arg_num == 0 && !i->zero_flag && i->min_flag)
				i->prinf_str = ft_strjoin_del("0x", i->prinf_str, 2);
			if (i->min_flag)
				f->arg_str = ft_strjoin_del(f->arg_str, i->prinf_str, 0);
			else
				f->arg_str = ft_strjoin_del(i->prinf_str, f->arg_str, 0);
		}
	}
}

void	pr_deal_with_digit(char type, t_prfgs *prfgs, t_prinf *prinf)
{
	pr_deal_with_prec_d(prfgs, prinf);
	if (pr_arg_is_sig(type) && prfgs->arg_num < 0)
		prfgs->arg_str = ft_strjoin_del("-", prfgs->arg_str, 2);
	pr_add_type_front(type, prfgs, prinf);
	pr_deal_with_width(type, prfgs, prinf);
	if (type == 'p' && prfgs->arg_num == 0 &&
			!prinf->zero_flag && !prinf->w_flag)
		prfgs->arg_str = ft_strjoin_del("0x", prfgs->arg_str, 2);
	if (type == 'p' && prfgs->arg_num == 0 &&
			!prinf->zero_flag && prinf->min_flag)
		ft_swapc(&prfgs->arg_str[1], &prfgs->arg_str[2]);
	if (type == 'X')
		prfgs->arg_str = ft_strtoupper(prfgs->arg_str);
}

int		pr_deal_with_char(t_prfgs *f, t_prinf *i)
{
	char cpy;

	cpy = *f->arg_str;
	if (i->w_flag)
	{
		if (!i->zero_flag)
			i->prinf_str = ft_strnew_set(i->w_flag - 1, ' ');
		else
			i->prinf_str = ft_strnew_set(i->w_flag - 1, '0');
		if (i->min_flag)
			f->arg_str = ft_strjoin_del(f->arg_str, i->prinf_str, 0);
		else
			f->arg_str = ft_strjoin_del(i->prinf_str, f->arg_str, 0);
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

void	pr_deal_with_perc(t_prfgs *prfgs, t_prinf *prinf)
{
	if (prinf->w_flag)
	{
		if (prinf->zero_flag)
			prinf->prinf_str =
				ft_strnew_set(prinf->w_flag - (prinf->len_arg), '0');
		else
			prinf->prinf_str =
				ft_strnew_set(prinf->w_flag - (prinf->len_arg), ' ');
		if (prinf->min_flag)
			prfgs->arg_str =
				ft_strjoin_del(prfgs->arg_str, prinf->prinf_str, 0);
		else
			prfgs->arg_str =
				ft_strjoin_del(prinf->prinf_str, prfgs->arg_str, 0);
	}
}

int		pr_deal_with_cw(t_prfgs *prfgs, t_prinf *prinf)
{
	if (*prfgs->arg_str == 0)
	{
		prfgs->format_tmp = ft_strjoin(prfgs->format_tmp, " ");
		prinf->pos_bz = ft_strlen(prfgs->format_tmp);
		return (1);
	}
	return (0);
}
