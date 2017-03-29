/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:53:09 by agouby            #+#    #+#             */
/*   Updated: 2017/03/14 08:32:48 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pr_add_space_b(char *str)
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

void	pr_reverse_bits(char *str)
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

void	pr_deal_with_prec_d(t_prfgs *prfgs, t_prinf *prinf)
{
	if (prinf->wrong_prec && prfgs->arg_num == 0 && prinf->pstar == 0)
		*prfgs->arg_str = '\0';
	if (prinf->prec_flag)
	{
		if (prinf->prec_size > 0)
		{
			prfgs->arg_str = ft_strjoin_del(
				ft_strnew_set(prinf->prec_size, '0'), prfgs->arg_str, 0);
			prinf->len_arg = (int)ft_strlen(prfgs->arg_str);
		}
	}
}

void	pr_add_type_front(char type, t_prfgs *prfgs, t_prinf *prinf)
{
	if (prinf->sp_flag)
		prfgs->arg_str = ft_strjoin_del(" ", prfgs->arg_str, 2);
	if (prinf->plus_flag)
		prfgs->arg_str = ft_strjoin_del("+", prfgs->arg_str, 2);
	if ((type == 'x' || type == 'X')
			&& prfgs->arg_num != 0 && prinf->hash_flag && !prinf->zero_flag)
		prfgs->arg_str = ft_strjoin_del("0x", prfgs->arg_str, 2);
	if ((type == 'o' || type == 'O')
			&& prinf->hash_flag && !prinf->prec_flag
			&& (prfgs->arg_num > 0 || prinf->wrong_prec))
		prfgs->arg_str = ft_strjoin_del("0", prfgs->arg_str, 2);
	if (type == 'p' && prfgs->arg_num)
		prfgs->arg_str = ft_strjoin_del("0x", prfgs->arg_str, 2);
	prinf->len_arg = (int)ft_strlen(prfgs->arg_str);
}

void	pr_deal_with_zero(char type, t_prfgs *prfgs, t_prinf *prinf)
{
	prinf->prinf_str = ft_strnew_set(prinf->w_flag - (prinf->len_arg), '0');
	if (prinf->sp_flag)
		prfgs->arg_str = ft_strjoin_del(prfgs->arg_str, prinf->prinf_str, 1);
	if (prinf->sp_flag)
		ft_swapc(&prinf->prinf_str[0], &prinf->prinf_str[1]);
	if (prinf->plus_flag)
	{
		*prfgs->arg_str = '0';
		*prinf->prinf_str = '+';
	}
	if (prfgs->arg_num < 0)
	{
		*prfgs->arg_str = '0';
		*prinf->prinf_str = '-';
	}
	if ((type == 'x' || type == 'X')
			&& prfgs->arg_num != 0 && prinf->hash_flag)
		prinf->prinf_str[1] = 'x';
	if (type == 'p')
		prinf->prinf_str[1] = 'x';
}
