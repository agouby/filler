/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:21:48 by agouby            #+#    #+#             */
/*   Updated: 2017/03/08 00:00:44 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_get_arg_ds(char type, va_list args, t_prfgs *prfgs, t_prinf *prinf)
{
	if (prinf->ll_flag)
		prfgs->arg_num = (long long)va_arg(args, long long);
	else if (prinf->l_flag || type == 'D')
		prfgs->arg_num = (long)va_arg(args, long);
	else if (prinf->j_flag)
		prfgs->arg_num = (intmax_t)va_arg(args, intmax_t);
	else if (prinf->z_flag)
		prfgs->arg_num = (long long)va_arg(args, long long);
	else if (prinf->h_flag)
		prfgs->arg_num = (short)va_arg(args, int);
	else if (prinf->hh_flag)
		prfgs->arg_num = (char)va_arg(args, int);
	else
		prfgs->arg_num = (int)va_arg(args, int);
	prfgs->arg_str = pr_choose_conv(prfgs->arg_num, prinf);
}

void	pr_get_arg_du(char type, va_list args, t_prfgs *prfgs, t_prinf *prinf)
{
	if (prinf->ll_flag)
		prfgs->arg_num = (unsigned long long)va_arg(args, unsigned long long);
	else if (prinf->l_flag || type == 'p')
		prfgs->arg_num = va_arg(args, unsigned long);
	else if (prinf->j_flag)
		prfgs->arg_num = (uintmax_t)va_arg(args, uintmax_t);
	else if (prinf->z_flag)
		prfgs->arg_num = (size_t)va_arg(args, size_t);
	else if (prinf->h_flag)
		prfgs->arg_num = (unsigned short)va_arg(args, unsigned int);
	else if (prinf->hh_flag)
		prfgs->arg_num = (unsigned char)va_arg(args, unsigned int);
	else
		prfgs->arg_num = (unsigned int)va_arg(args, unsigned int);
	prfgs->arg_str = pr_choose_conv_u(type, prfgs->arg_num, prinf);
}

void	pr_get_arg_c(char type, va_list args, t_prfgs *prfgs, t_prinf *prinf)
{
	wchar_t wchar;

	if (type == 'c' && !prinf->l_flag)
		prfgs->arg_str = ft_strnew_set(1, (char)va_arg(args, int));
	else
	{
		wchar = va_arg(args, wchar_t);
		prfgs->arg_str = ft_strnew(pr_get_charlen(wchar));
		pr_trans_char(wchar, prfgs->arg_str, 0);
	}
}

void	pr_get_arg_s(char type, va_list args, t_prfgs *prfgs, t_prinf *prinf)
{
	if (type == 's' && !prinf->l_flag)
	{
		prfgs->arg_str = ft_strdup((char *)va_arg(args, char *));
		if (!prfgs->arg_str)
			prfgs->arg_str = ft_strdup("(null)");
	}
	else
	{
		prfgs->wtmp = va_arg(args, wchar_t *);
		if (!prfgs->wtmp)
			prfgs->arg_str = ft_strdup("(null)");
		else
			prfgs->arg_str = pr_transform_wstr(prfgs->wtmp);
	}
}
