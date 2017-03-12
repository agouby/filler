/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 14:35:40 by agouby            #+#    #+#             */
/*   Updated: 2017/03/07 23:29:45 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	change_modifier(t_infos *infos)
{
	if (infos->z_flag == 0 && infos->l_flag == 0 && infos->ll_flag == 0 &&
			infos->h_flag == 0 && infos->hh_flag == 0 && infos->j_flag == 0)
		infos->no_modif = 1;
}

int		is_no_type(char type)
{
	return (ft_strchr_b("aAeEfFgGhHIjJkKlLmMnNPqQrRtTvVwWzZ{}()[]\n", type));
}

char	change_type(char type, t_infos *infos)
{
	if (type == 'U' || type == 'O' || type == 'D')
	{
		type = ft_tolower(type);
		infos->l_flag = 1;
	}
	return (type);
}

char	*choose_conv(long long arg_num, t_infos *infos)
{
	char *str;

	str = NULL;
	if (infos->hh_flag)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	else if (infos->h_flag)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	else if (infos->l_flag)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	else if (infos->j_flag)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	else if (infos->z_flag)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	else if (infos->ll_flag)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	else if (infos->no_modif)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	return (str);
}

char	*choose_conv_u(char type, unsigned long long nb, t_infos *infos)
{
	char	*str;
	int		conv;

	str = NULL;
	conv = get_conversion(type);
	if (infos->hh_flag)
		str = ft_itoa_ubase(nb, conv);
	else if (infos->h_flag)
		str = ft_itoa_ubase(nb, conv);
	else if (infos->l_flag)
		str = ft_itoa_ubase(nb, conv);
	else if (infos->j_flag)
		str = ft_itoa_ubase(nb, conv);
	else if (infos->z_flag)
		str = ft_itoa_ubase(nb, conv);
	else if (infos->ll_flag)
		str = ft_itoa_ubase(nb, conv);
	else if (infos->no_modif)
		str = ft_itoa_ubase(nb, conv);
	return (str);
}
