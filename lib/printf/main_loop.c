/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:24:06 by agouby            #+#    #+#             */
/*   Updated: 2017/03/06 22:01:50 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pr_flag_is_empty(int fd, t_prfgs *prfgs, t_prinf *prinf)
{
	int len;

	len = ft_strlen(prfgs->format_tmp);
	write(fd, prfgs->format_tmp, len);
	free(prfgs->array);
	ft_strdel(&prfgs->format_tmp);
	free(prfgs);
	free(prinf);
	return (len);
}

void	pr_get_all(va_list args, t_prfgs *prfgs, t_prinf *prinf)
{
	pr_get_prinf(prinf, prfgs->str_flag);
	pr_get_arg(args, prfgs, prinf);
}

int		pr_del_and_print(int fd, t_prfgs *prfgs, t_prinf *prinf)
{
	int ret;

	ret = ft_strlen(prfgs->format_tmp);
	if (prinf->pos_bz)
		prfgs->format_tmp[prinf->pos_bz - 1] = '\0';
	write(fd, prfgs->format_tmp, ret);
	ft_strdel(&prfgs->format_tmp);
	free(prfgs->array);
	free(prfgs);
	free(prinf);
	return (ret);
}

void	pr_join_all(t_prfgs *prfgs, char *format)
{
	prfgs->format_tmp = ft_strjoin_del(prfgs->format_tmp, prfgs->arg_str, 0);
	if (prfgs->i + 1 == prfgs->nb_perc)
		prfgs->format_tmp = ft_strnjoin_del_1(prfgs->format_tmp, format,
			prfgs->array[prfgs->i] + prfgs->len_flag + 1, ft_strlen(format));
	else
		prfgs->format_tmp = ft_strnjoin_del_1(prfgs->format_tmp, format,
				prfgs->array[prfgs->i] + prfgs->len_flag + 1,
				prfgs->array[prfgs->i + 1]);
}

int		pr_store_all(va_list args, t_prfgs *prfgs, t_prinf *prinf, char *format)
{
	if (prfgs->nb_perc > 0)
	{
		prfgs->format_tmp = ft_strsub(format, 0, prfgs->array[0]);
		while (prfgs->i < prfgs->nb_perc)
		{
			prfgs->str_flag = pr_store_prfgs(prfgs->array[prfgs->i],
					&prfgs->e_flag, &prfgs->len_flag, format);
			if (!prfgs->str_flag)
				return (0);
			pr_get_all(args, prfgs, prinf);
			prfgs->empty_arg += pr_put_prinf_in_str(prfgs, prinf);
			pr_join_all(prfgs, (char *)format);
			prfgs->i++;
			ft_strdel(&prfgs->str_flag);
		}
	}
	else
		prfgs->format_tmp = ft_strdup(format);
	return (prfgs->empty_arg);
}
