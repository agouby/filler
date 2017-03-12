/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:48:04 by agouby            #+#    #+#             */
/*   Updated: 2017/03/07 23:00:27 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_end_flag(char c)
{
	char *srch;

	srch = "sSpdDioOuUxXcC%aAbBeEfFgGHIJkKLmMnNpPqQrRtTvVwWZ{}()[]\n";
	return (ft_strchr_b(srch, c));
}

static int	get_end_flag(int s, int *e, const char *format)
{
	while (format[s])
	{
		if (is_end_flag(format[s + 1]))
		{
			*e = s + 1;
			return (*e);
		}
		s++;
	}
	return (0);
}

char		*store_flags(int s, int *e, int *len, const char *format)
{
	char	*str_flag;

	str_flag = NULL;
	get_end_flag(s, e, format);
	*len = *e - s;
	if (*len > 0)
		str_flag = ft_strsub(format, s + 1, *len);
	return (str_flag);
}

void		modify_infos(char type, t_infos *infos, t_flags *flags)
{
	if (infos->zero_flag)
	{
		if (infos->min_flag || (infos->prec_flag && (arg_is_digit(type))))
			infos->zero_flag = 0;
	}
	if (infos->min_flag)
	{
		if (!infos->w_flag)
			infos->min_flag = 0;
	}
	if (infos->sp_flag)
	{
		if (!arg_is_signed(type) || (int)flags->arg_num < 0 || infos->plus_flag)
			infos->sp_flag = 0;
	}
	if (infos->plus_flag)
	{
		if (!arg_is_signed(type) || (int)flags->arg_num < 0)
			infos->plus_flag = 0;
	}
	if (type == 'p')
	{
		infos->l_flag = 1;
		infos->hash_flag = 1;
	}
}

int			put_infos_in_str(t_flags *flags, t_infos *infos)
{
	char	type;

	type = get_type(flags);
	if (type != 'C' && type != 'S')
		infos->len_arg = (int)ft_strlen(flags->arg_str);
	infos->prec_size = infos->prec_flag - infos->len_arg;
	modify_infos(type, infos, flags);
	if (is_no_type(type))
		deal_with_notype(flags, infos);
	else if (arg_is_digit(type))
		deal_with_digit(type, flags, infos);
	else if (arg_is_char(type))
		return (deal_with_char(flags, infos));
	else if (type == '%')
		deal_with_perc(flags, infos);
	else if (arg_is_string(type))
		deal_with_s(flags, infos);
	else if (type == 'C')
		return (deal_with_cw(flags, infos));
	else if (type == 'S')
		deal_with_sw(flags, infos);
	else if (type == 'b' || type == 'B')
		deal_with_b(type, flags);
	return (0);
}
