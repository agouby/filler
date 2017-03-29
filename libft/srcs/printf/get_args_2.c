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

void	pr_get_arg_perc(t_prfgs *prfgs)
{
	prfgs->arg_str = ft_strnew_set(1, '%');
}

void	pr_get_arg_notype(char type, t_prfgs *prfgs)
{
	prfgs->arg_str = ft_strnew_set(1, type);
}

void	pr_get_arg_b(va_list args, t_prfgs *prfgs)
{
	prfgs->arg_str = ft_itoa_ubase(va_arg(args, unsigned long long), 2);
}

void	pr_get_star_in_flag(va_list args, t_prinf *prinf)
{
	if (prinf->wstar && prinf->w_flag == 0)
	{
		prinf->w_flag = va_arg(args, int);
		if (prinf->w_flag < 0)
		{
			prinf->is_min = 1;
			prinf->min_flag = 1;
			prinf->w_flag = ABS(prinf->w_flag);
		}
	}
	if (prinf->pstar)
		prinf->prec_flag = va_arg(args, int);
}

void	pr_get_arg(va_list args, t_prfgs *prfgs, t_prinf *prinf)
{
	char type;

	type = pr_change_type(pr_get_type(prfgs), prinf);
	pr_change_modifier(prinf);
	pr_get_star_in_flag(args, prinf);
	if (prinf->prec_flag < 0 && (type != 'S' && type != 's'))
		prinf->prec_flag = 0;
	if (pr_is_no_type(type))
		pr_get_arg_notype(type, prfgs);
	else if (pr_arg_is_sig(type))
		pr_get_arg_ds(type, args, prfgs, prinf);
	else if (pr_arg_is_unsigned(type))
		pr_get_arg_du(type, args, prfgs, prinf);
	else if (pr_arg_is_char(type) || type == 'C')
		pr_get_arg_c(type, args, prfgs, prinf);
	else if (pr_arg_is_string(type) || type == 'S')
		pr_get_arg_s(type, args, prfgs, prinf);
	else if (type == '%')
		pr_get_arg_perc(prfgs);
	else if (type == 'b' || type == 'B')
		pr_get_arg_b(args, prfgs);
}
