/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:55:13 by agouby            #+#    #+#             */
/*   Updated: 2017/03/09 02:57:39 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dprintf(int fd, const char *format, ...)
{
	t_flags *flags;
	t_infos *infos;
	va_list args;

	va_start(args, format);
	init_all_struct(&infos, &flags);
	flags->nb_perc = nb_perc(format);
	get_index_perc(flags, format);
	if (store_all(args, flags, infos, (char *)format) == 0)
		return (flag_is_empty(fd, flags, infos));
	va_end(args);
	return (del_and_print(fd, flags, infos));
}

int		ft_printf(const char *format, ...)
{
	t_flags *flags;
	t_infos *infos;
	va_list args;

	va_start(args, format);
	init_all_struct(&infos, &flags);
	flags->nb_perc = nb_perc(format);
	get_index_perc(flags, format);
	if (store_all(args, flags, infos, (char *)format) == 0)
		return (flag_is_empty(1, flags, infos));
	va_end(args);
	return (del_and_print(1, flags, infos));
}
