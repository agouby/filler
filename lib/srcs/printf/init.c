/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:44:30 by agouby            #+#    #+#             */
/*   Updated: 2017/03/13 01:00:53 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pr_init_prinf(t_prinf *prinf)
{
	prinf->hash_flag = 0;
	prinf->min_flag = 0;
	prinf->plus_flag = 0;
	prinf->sp_flag = 0;
	prinf->zero_flag = 0;
	prinf->prec_flag = 0;
	prinf->w_flag = 0;
	prinf->z_flag = 0;
	prinf->ll_flag = 0;
	prinf->hh_flag = 0;
	prinf->j_flag = 0;
	prinf->l_flag = 0;
	prinf->h_flag = 0;
	prinf->no_modif = 0;
	prinf->wrong_prec = 0;
	prinf->len_arg = 0;
	prinf->prinf_str = NULL;
	prinf->prec_size = 0;
	prinf->pstar = 0;
	prinf->wstar = 0;
}

static t_prfgs	*pr_init_prfgs_struct(t_prfgs *prfgs)
{
	prfgs = (t_prfgs *)malloc(sizeof(t_prfgs));
	prfgs->e_flag = 0;
	prfgs->array = NULL;
	prfgs->i = 0;
	prfgs->len_flag = 0;
	prfgs->str_flag = NULL;
	prfgs->arg_num = 0;
	prfgs->arg_str = NULL;
	prfgs->wtmp = NULL;
	prfgs->format_tmp = NULL;
	prfgs->empty_arg = 0;
	prfgs->nb_perc = 0;
	return (prfgs);
}

static t_prinf	*pr_init_prinf_struct(t_prinf *prinf)
{
	prinf = (t_prinf *)malloc(sizeof(t_prinf));
	pr_init_prinf(prinf);
	prinf->pos_bz = 0;
	return (prinf);
}

void			pr_init_all_struct(t_prinf **prinf, t_prfgs **prfgs)
{
	*prfgs = pr_init_prfgs_struct(*prfgs);
	*prinf = pr_init_prinf_struct(*prinf);
}
