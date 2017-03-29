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

void	pr_change_modifier(t_prinf *prinf)
{
	if (prinf->z_flag == 0 && prinf->l_flag == 0 && prinf->ll_flag == 0 &&
			prinf->h_flag == 0 && prinf->hh_flag == 0 && prinf->j_flag == 0)
		prinf->no_modif = 1;
}

int		pr_is_no_type(char type)
{
	return (ft_strchr_b("aAeEfFgGhHIjJkKlLmMnNPqQrRtTvVwWzZ{}()[]\n", type));
}

char	pr_change_type(char type, t_prinf *prinf)
{
	if (type == 'U' || type == 'O' || type == 'D')
	{
		type = ft_tolower(type);
		prinf->l_flag = 1;
	}
	return (type);
}

char	*pr_choose_conv(long long arg_num, t_prinf *prinf)
{
	char *str;

	str = NULL;
	if (prinf->hh_flag)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	else if (prinf->h_flag)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	else if (prinf->l_flag)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	else if (prinf->j_flag)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	else if (prinf->z_flag)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	else if (prinf->ll_flag)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	else if (prinf->no_modif)
		str = ft_itoa_ubase(ABS(arg_num), 10);
	return (str);
}

char	*pr_choose_conv_u(char type, unsigned long long nb, t_prinf *prinf)
{
	char	*str;
	int		conv;

	str = NULL;
	conv = pr_get_conversion(type);
	if (prinf->hh_flag)
		str = ft_itoa_ubase(nb, conv);
	else if (prinf->h_flag)
		str = ft_itoa_ubase(nb, conv);
	else if (prinf->l_flag)
		str = ft_itoa_ubase(nb, conv);
	else if (prinf->j_flag)
		str = ft_itoa_ubase(nb, conv);
	else if (prinf->z_flag)
		str = ft_itoa_ubase(nb, conv);
	else if (prinf->ll_flag)
		str = ft_itoa_ubase(nb, conv);
	else if (prinf->no_modif)
		str = ft_itoa_ubase(nb, conv);
	return (str);
}
