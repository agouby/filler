/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prfgs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:48:04 by agouby            #+#    #+#             */
/*   Updated: 2017/03/07 23:00:27 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pr_is_end_flag(char c)
{
	char *srch;

	srch = "sSpdDioOuUxXcC%aAbBeEfFgGHIJkKLmMnNpPqQrRtTvVwWZ{}()[]\n";
	return (ft_strchr_b(srch, c));
}

static int	pr_get_end_flag(int s, int *e, const char *format)
{
	while (format[s])
	{
		if (pr_is_end_flag(format[s + 1]))
		{
			*e = s + 1;
			return (*e);
		}
		s++;
	}
	return (0);
}

char		*pr_store_prfgs(int s, int *e, int *len, const char *format)
{
	char	*str_flag;

	str_flag = NULL;
	pr_get_end_flag(s, e, format);
	*len = *e - s;
	if (*len > 0)
		str_flag = ft_strsub(format, s + 1, *len);
	return (str_flag);
}

void		pr_modify_prinf(char type, t_prinf *prinf, t_prfgs *prfgs)
{
	if (prinf->zero_flag)
	{
		if (prinf->min_flag || (prinf->prec_flag && (pr_arg_is_digit(type))))
			prinf->zero_flag = 0;
	}
	if (prinf->min_flag)
	{
		if (!prinf->w_flag)
			prinf->min_flag = 0;
	}
	if (prinf->sp_flag)
	{
		if (!pr_arg_is_sig(type) || (int)prfgs->arg_num < 0 || prinf->plus_flag)
			prinf->sp_flag = 0;
	}
	if (prinf->plus_flag)
	{
		if (!pr_arg_is_sig(type) || (int)prfgs->arg_num < 0)
			prinf->plus_flag = 0;
	}
	if (type == 'p')
	{
		prinf->l_flag = 1;
		prinf->hash_flag = 1;
	}
}

int			pr_put_prinf_in_str(t_prfgs *prfgs, t_prinf *prinf)
{
	char	type;

	type = pr_get_type(prfgs);
	if (type != 'C' && type != 'S')
		prinf->len_arg = (int)ft_strlen(prfgs->arg_str);
	prinf->prec_size = prinf->prec_flag - prinf->len_arg;
	pr_modify_prinf(type, prinf, prfgs);
	if (pr_is_no_type(type))
		pr_deal_with_notype(prfgs, prinf);
	else if (pr_arg_is_digit(type))
		pr_deal_with_digit(type, prfgs, prinf);
	else if (pr_arg_is_char(type))
		return (pr_deal_with_char(prfgs, prinf));
	else if (type == '%')
		pr_deal_with_perc(prfgs, prinf);
	else if (pr_arg_is_string(type))
		pr_deal_with_s(prfgs, prinf);
	else if (type == 'C')
		return (pr_deal_with_cw(prfgs, prinf));
	else if (type == 'S')
		pr_deal_with_sw(prfgs, prinf);
	else if (type == 'b' || type == 'B')
		pr_deal_with_b(type, prfgs);
	return (0);
}
