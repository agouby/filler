/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prinf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:27:50 by agouby            #+#    #+#             */
/*   Updated: 2017/03/03 00:55:36 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pr_set_wrong_prec(t_prinf *prinf)
{
	prinf->wrong_prec = 1;
	return ;
}

static void		pr_get_precision(t_prinf *prinf, char *str_flag)
{
	while (*str_flag)
	{
		if (*str_flag == '.')
		{
			while (*str_flag == '.')
				str_flag++;
			if (!ft_isdigit(*str_flag))
				pr_set_wrong_prec(prinf);
			while (*str_flag == '0')
				str_flag++;
			if (ft_isdigit(*str_flag))
				prinf->prec_flag = ft_atoi(str_flag);
			else
				pr_set_wrong_prec(prinf);
			while (ft_isdigit(*str_flag))
				str_flag++;
			if (*str_flag == '.')
			{
				prinf->prec_flag = 1;
				return ;
			}
		}
		str_flag++;
	}
}

static void		pr_get_width(t_prinf *prinf, char *str_flag)
{
	while (*str_flag && !ft_isdigit(*str_flag))
	{
		if (*(str_flag + 1) == '0' && *str_flag != '.')
		{
			prinf->zero_flag = 1;
			while (*(str_flag + 1) == '0')
				str_flag++;
		}
		if (*str_flag == '.')
			return ;
		str_flag++;
	}
	if (*str_flag == '0')
	{
		prinf->zero_flag = 1;
		str_flag++;
	}
	while (!ft_isdigit(*str_flag) && *str_flag && *str_flag != '.')
		str_flag++;
	prinf->w_flag = ft_atoi(str_flag);
}

static void		pr_get_other_prinf(t_prinf *prinf, char *str_flag)
{
	while (*str_flag)
	{
		if (*str_flag == '#')
			prinf->hash_flag = 1;
		else if (*str_flag == '-')
			prinf->min_flag = 1;
		else if (*str_flag == '+')
			prinf->plus_flag = 1;
		else if (*str_flag == ' ')
			prinf->sp_flag = 1;
		else if (*str_flag == 'l' && *(str_flag + 1) != 'l')
			prinf->l_flag = 1;
		else if (*str_flag == 'l' && *(str_flag + 1) == 'l' && str_flag++)
			prinf->ll_flag = 1;
		else if (*str_flag == 'h' && *(str_flag + 1) != 'h')
			prinf->h_flag = 1;
		else if (*str_flag == 'h' && *(str_flag + 1) == 'h' && str_flag++)
			prinf->hh_flag = 1;
		else if (*str_flag == 'j')
			prinf->j_flag = 1;
		else if (*str_flag == 'z')
			prinf->z_flag = 1;
		str_flag++;
	}
}

void			pr_get_prinf(t_prinf *prinf, char *str_flag)
{
	if (!str_flag)
		return ;
	pr_init_prinf(prinf);
	pr_get_star(prinf, str_flag);
	pr_get_width(prinf, str_flag);
	pr_get_precision(prinf, str_flag);
	pr_get_other_prinf(prinf, str_flag);
}
