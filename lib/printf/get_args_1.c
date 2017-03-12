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

void	get_arg_ds(char type, va_list args, t_flags *flags, t_infos *infos)
{
	if (infos->ll_flag)
		flags->arg_num = (long long)va_arg(args, long long);
	else if (infos->l_flag || type == 'D')
		flags->arg_num = (long)va_arg(args, long);
	else if (infos->j_flag)
		flags->arg_num = (intmax_t)va_arg(args, intmax_t);
	else if (infos->z_flag)
		flags->arg_num = (long long)va_arg(args, long long);
	else if (infos->h_flag)
		flags->arg_num = (short)va_arg(args, int);
	else if (infos->hh_flag)
		flags->arg_num = (char)va_arg(args, int);
	else
		flags->arg_num = (int)va_arg(args, int);
	flags->arg_str = choose_conv(flags->arg_num, infos);
}

void	get_arg_du(char type, va_list args, t_flags *flags, t_infos *infos)
{
	if (infos->ll_flag)
		flags->arg_num = (unsigned long long)va_arg(args, unsigned long long);
	else if (infos->l_flag || type == 'p')
		flags->arg_num = va_arg(args, unsigned long);
	else if (infos->j_flag)
		flags->arg_num = (uintmax_t)va_arg(args, uintmax_t);
	else if (infos->z_flag)
		flags->arg_num = (size_t)va_arg(args, size_t);
	else if (infos->h_flag)
		flags->arg_num = (unsigned short)va_arg(args, unsigned int);
	else if (infos->hh_flag)
		flags->arg_num = (unsigned char)va_arg(args, unsigned int);
	else
		flags->arg_num = (unsigned int)va_arg(args, unsigned int);
	flags->arg_str = choose_conv_u(type, flags->arg_num, infos);
}

void	get_arg_c(char type, va_list args, t_flags *flags, t_infos *infos)
{
	wchar_t wchar;

	if (type == 'c' && !infos->l_flag)
		flags->arg_str = ft_strnew_set(1, (char)va_arg(args, int));
	else
	{
		wchar = va_arg(args, wchar_t);
		flags->arg_str = ft_strnew(get_charlen(wchar));
		transform_char(wchar, flags->arg_str, 0);
	}
}

void	get_arg_s(char type, va_list args, t_flags *flags, t_infos *infos)
{
	if (type == 's' && !infos->l_flag)
	{
		flags->arg_str = ft_strdup((char *)va_arg(args, char *));
		if (!flags->arg_str)
			flags->arg_str = ft_strdup("(null)");
	}
	else
	{
		flags->wtmp = va_arg(args, wchar_t *);
		if (!flags->wtmp)
			flags->arg_str = ft_strdup("(null)");
		else
			flags->arg_str = transform_wstr(flags->wtmp);
	}
}
