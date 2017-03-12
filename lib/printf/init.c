/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:44:30 by agouby            #+#    #+#             */
/*   Updated: 2017/03/09 02:55:49 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_infos(t_infos *infos)
{
	infos->hash_flag = 0;
	infos->min_flag = 0;
	infos->plus_flag = 0;
	infos->sp_flag = 0;
	infos->zero_flag = 0;
	infos->prec_flag = 0;
	infos->w_flag = 0;
	infos->z_flag = 0;
	infos->ll_flag = 0;
	infos->hh_flag = 0;
	infos->j_flag = 0;
	infos->l_flag = 0;
	infos->h_flag = 0;
	infos->no_modif = 0;
	infos->wrong_prec = 0;
	infos->len_arg = 0;
	infos->infos_str = NULL;
	infos->prec_size = 0;
	infos->pstar = 0;
	infos->wstar = 0;
}

static t_flags	*init_flags_struct(t_flags *flags)
{
	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->e_flag = 0;
	flags->array = NULL;
	flags->i = 0;
	flags->len_flag = 0;
	flags->str_flag = NULL;
	flags->arg_num = 0;
	flags->arg_str = NULL;
	flags->wtmp = NULL;
	flags->format_tmp = NULL;
	flags->empty_arg = 0;
	flags->nb_perc = 0;
	return (flags);
}

static t_infos	*init_infos_struct(t_infos *infos)
{
	infos = (t_infos *)malloc(sizeof(t_infos));
	init_infos(infos);
	infos->pos_bz = 0;
	return (infos);
}

void			init_all_struct(t_infos **infos, t_flags **flags)
{
	*flags = init_flags_struct(*flags);
	*infos = init_infos_struct(*infos);
}
