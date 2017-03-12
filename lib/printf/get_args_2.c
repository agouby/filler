/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:21:55 by agouby            #+#    #+#             */
/*   Updated: 2017/03/06 21:35:58 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_arg_perc(t_flags *flags)
{
	flags->arg_str = ft_strnew_set(1, '%');
}

void	get_arg_notype(char type, t_flags *flags)
{
	flags->arg_str = ft_strnew_set(1, type);
}

void	get_arg_b(va_list args, t_flags *flags)
{
	flags->arg_str = ft_itoa_ubase(va_arg(args, unsigned long long), 2);
}

void	get_star_in_flag(va_list args, t_infos *infos)
{
	if (infos->wstar && infos->w_flag == 0)
	{
		infos->w_flag = va_arg(args, int);
		if (infos->w_flag < 0)
		{
			infos->is_min = 1;
			infos->min_flag = 1;
			infos->w_flag = ABS(infos->w_flag);
		}
	}
	if (infos->pstar)
		infos->prec_flag = va_arg(args, int);
}

void	get_arg(va_list args, t_flags *flags, t_infos *infos)
{
	char type;

	type = change_type(get_type(flags), infos);
	change_modifier(infos);
	get_star_in_flag(args, infos);
	if (infos->prec_flag < 0 && (type != 'S' && type != 's'))
		infos->prec_flag = 0;
	if (is_no_type(type))
		get_arg_notype(type, flags);
	else if (arg_is_signed(type))
		get_arg_ds(type, args, flags, infos);
	else if (arg_is_unsigned(type))
		get_arg_du(type, args, flags, infos);
	else if (arg_is_char(type) || type == 'C')
		get_arg_c(type, args, flags, infos);
	else if (arg_is_string(type) || type == 'S')
		get_arg_s(type, args, flags, infos);
	else if (type == '%')
		get_arg_perc(flags);
	else if (type == 'b' || type == 'B')
		get_arg_b(args, flags);
}
