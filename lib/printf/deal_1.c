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

void	pr_apply_width(t_prfgs *prfgs, t_prinf *prinf)
{
	prinf->len_arg = (int)ft_strlen(prfgs->arg_str);
	if (prinf->len_arg >= 0 && prinf->w_flag - prinf->len_arg > 0)
	{
		if (!prinf->zero_flag)
			prinf->prinf_str =
				ft_strnew_set(prinf->w_flag - (prinf->len_arg), ' ');
		else
			prinf->prinf_str =
				ft_strnew_set(prinf->w_flag - (prinf->len_arg), '0');
		if (prinf->min_flag)
			prfgs->arg_str =
				ft_strjoin_del(prfgs->arg_str, prinf->prinf_str, 0);
		else
			prfgs->arg_str =
				ft_strjoin_del(prinf->prinf_str, prfgs->arg_str, 0);
	}
}

void	pr_deal_with_s(t_prfgs *prfgs, t_prinf *prinf)
{
	if ((prinf->pstar && prinf->prec_flag == 0) ||
			(prinf->wrong_prec && !prinf->pstar))
		*prfgs->arg_str = '\0';
	if (prinf->prec_flag)
	{
		if (prinf->prec_flag > 0)
			prfgs->arg_str = ft_strsub(prfgs->arg_str, 0, prinf->prec_flag);
	}
	if (prinf->w_flag)
		pr_apply_width(prfgs, prinf);
}

void	pr_deal_with_sw(t_prfgs *prfgs, t_prinf *prinf)
{
	int i;
	int n;
	int cut;

	cut = prinf->prec_flag;
	n = 0;
	i = 0;
	if (prinf->wrong_prec)
		*prfgs->arg_str = '\0';
	if (!prfgs->wtmp)
		return ;
	while (prfgs->wtmp[i] != '\0' && cut >= pr_get_charlen(prfgs->wtmp[i]))
	{
		n += pr_get_charlen(prfgs->wtmp[i]);
		cut -= pr_get_charlen(prfgs->wtmp[i]);
		i++;
	}
	if (prinf->prec_flag)
	{
		if (prinf->prec_flag > 0)
			prfgs->arg_str = ft_strsub(prfgs->arg_str, 0, n);
	}
	if (prinf->w_flag)
		pr_apply_width(prfgs, prinf);
}

void	pr_deal_with_b(char type, t_prfgs *prfgs)
{
	int len;

	len = (int)ft_strlen(prfgs->arg_str);
	if (len % 8 > 4)
		len = 4 - len % 4;
	else
		len = 8 - len % 8;
	if (len % 8)
		prfgs->arg_str =
			ft_strjoin_del(ft_strnew_set(len, '0'), prfgs->arg_str, 0);
	if (type == 'B')
		pr_reverse_bits(prfgs->arg_str);
	prfgs->arg_str = pr_add_space_b(prfgs->arg_str);
}

void	pr_deal_with_notype(t_prfgs *prfgs, t_prinf *prinf)
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
