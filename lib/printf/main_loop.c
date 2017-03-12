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

int		flag_is_empty(int fd, t_flags *flags, t_infos *infos)
{
	int len;

	len = ft_strlen(flags->format_tmp);
	write(fd, flags->format_tmp, len);
	free(flags->array);
	ft_strdel(&flags->format_tmp);
	free(flags);
	free(infos);
	return (len);
}

void	get_all(va_list args, t_flags *flags, t_infos *infos)
{
	get_infos(infos, flags->str_flag);
	get_arg(args, flags, infos);
}

int		del_and_print(int fd, t_flags *flags, t_infos *infos)
{
	int ret;

	ret = ft_strlen(flags->format_tmp);
	if (infos->pos_bz)
		flags->format_tmp[infos->pos_bz - 1] = '\0';
	write(fd, flags->format_tmp, ret);
	ft_strdel(&flags->format_tmp);
	free(flags->array);
	free(flags);
	free(infos);
	return (ret);
}

void	join_all(t_flags *flags, char *format)
{
	flags->format_tmp = ft_strjoin_del(flags->format_tmp, flags->arg_str, 0);
	if (flags->i + 1 == flags->nb_perc)
		flags->format_tmp = ft_strnjoin_del_1(flags->format_tmp, format,
			flags->array[flags->i] + flags->len_flag + 1, ft_strlen(format));
	else
		flags->format_tmp = ft_strnjoin_del_1(flags->format_tmp, format,
				flags->array[flags->i] + flags->len_flag + 1,
				flags->array[flags->i + 1]);
}

int		store_all(va_list args, t_flags *flags, t_infos *infos, char *format)
{
	if (flags->nb_perc > 0)
	{
		flags->format_tmp = ft_strsub(format, 0, flags->array[0]);
		while (flags->i < flags->nb_perc)
		{
			flags->str_flag = store_flags(flags->array[flags->i],
					&flags->e_flag, &flags->len_flag, format);
			if (!flags->str_flag)
				return (0);
			get_all(args, flags, infos);
			flags->empty_arg += put_infos_in_str(flags, infos);
			join_all(flags, (char *)format);
			flags->i++;
			ft_strdel(&flags->str_flag);
		}
	}
	else
		flags->format_tmp = ft_strdup(format);
	return (flags->empty_arg);
}
