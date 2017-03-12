/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:53:09 by agouby            #+#    #+#             */
/*   Updated: 2017/03/07 22:59:59 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_space_b(char *str)
{
	int		l;
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	l = (int)ft_strlen(str);
	l += ((l - 1) % (l / 4));
	new = ft_strnew(l);
	while (i < l)
	{
		if (!((i + 1) % 5))
		{
			new[i] = ' ';
			j++;
		}
		else
			new[i] = str[i - j];
		i++;
	}
	ft_strdel(&str);
	return (new);
}

void	reverse_bits(char *str)
{
	while (*str)
	{
		if (*str == '0')
			*str = '1';
		else
			*str = '0';
		str++;
	}
}

void	deal_with_prec_d(t_flags *flags, t_infos *infos)
{
	if (infos->wrong_prec && flags->arg_num == 0 && infos->pstar == 0)
		*flags->arg_str = '\0';
	if (infos->prec_flag)
	{
		if (infos->prec_size > 0)
		{
			flags->arg_str = ft_strjoin_del(
				ft_strnew_set(infos->prec_size, '0'), flags->arg_str, 0);
			infos->len_arg = (int)ft_strlen(flags->arg_str);
		}
	}
}

void	add_type_front(char type, t_flags *flags, t_infos *infos)
{
	if (infos->sp_flag)
		flags->arg_str = ft_strjoin_del(" ", flags->arg_str, 2);
	if (infos->plus_flag)
		flags->arg_str = ft_strjoin_del("+", flags->arg_str, 2);
	if ((type == 'x' || type == 'X')
			&& flags->arg_num != 0 && infos->hash_flag && !infos->zero_flag)
		flags->arg_str = ft_strjoin_del("0x", flags->arg_str, 2);
	if ((type == 'o' || type == 'O')
			&& infos->hash_flag && !infos->prec_flag
			&& (flags->arg_num > 0 || infos->wrong_prec))
		flags->arg_str = ft_strjoin_del("0", flags->arg_str, 2);
	if (type == 'p' && flags->arg_num)
		flags->arg_str = ft_strjoin_del("0x", flags->arg_str, 2);
	infos->len_arg = (int)ft_strlen(flags->arg_str);
}

void	deal_with_zero(char type, t_flags *flags, t_infos *infos)
{
	infos->infos_str = ft_strnew_set(infos->w_flag - (infos->len_arg), '0');
	if (infos->sp_flag)
		flags->arg_str = ft_strjoin_del(flags->arg_str, infos->infos_str, 1);
	if (infos->sp_flag)
		ft_swapc(&infos->infos_str[0], &infos->infos_str[1]);
	if (infos->plus_flag)
	{
		*flags->arg_str = '0';
		*infos->infos_str = '+';
	}
	if (flags->arg_num < 0)
	{
		*flags->arg_str = '0';
		*infos->infos_str = '-';
	}
	if ((type == 'x' || type == 'X')
			&& flags->arg_num != 0 && infos->hash_flag)
		infos->infos_str[1] = 'x';
	if (type == 'p')
		infos->infos_str[1] = 'x';
}
